#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cstdio>
#include <memory>
#include <array>
#include <string>

using namespace std;

string database_file = "DataBase.txt";

/* Convert RGB row → string key */
string row_to_key(const vector<unsigned char>& row)
{
    stringstream ss;
    for (size_t i = 0; i < row.size(); i++)
    {
        ss << (int)row[i];
        if (i + 1 < row.size()) ss << ",";
    }
    return ss.str();
}

/* ================= FFmpeg Helpers ================= */

FILE* open_ffmpeg_read_pipe(const string& video)
{
    string cmd =
        "ffmpeg -loglevel quiet -i \"" + video +
        "\" -f rawvideo -pix_fmt rgb24 -";

    return _popen(cmd.c_str(), "rb");
}

FILE* open_ffmpeg_write_pipe(const string& output, int width, int height, int fps)
{
    string cmd =
        "ffmpeg -y -loglevel quiet -f rawvideo -pix_fmt rgb24 -s " +
        to_string(width) + "x" + to_string(height) +
        " -r " + to_string(fps) +
        " -i - -c:v libx264 -pix_fmt yuv420p \"" + output + "\"";

    return _popen(cmd.c_str(), "wb");
}

bool get_video_info(const string& video, int& width, int& height, int& fps)
{
    string cmd =
        "ffprobe -v error -select_streams v:0 "
        "-show_entries stream=width,height,r_frame_rate "
        "-of csv=p=0 \"" + video + "\"";

    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) return false;

    char buffer[256];
    string result;

    while (fgets(buffer, sizeof(buffer), pipe))
        result += buffer;

    _pclose(pipe);

    stringstream ss(result);
    string part;

    getline(ss, part, ','); width = stoi(part);
    getline(ss, part, ','); height = stoi(part);
    getline(ss, part, ',');

    int num = 0, den = 1;
    sscanf_s(part.c_str(), "%d/%d", &num, &den);

    fps = den ? num / den : 24;

    return true;
}

/* ================= ENCODE ================= */

void encode_video()
{
    string video_path;
    cout << "Enter Video File Name: ";
    getline(cin, video_path);

    int width, height, fps;
    if (!get_video_info(video_path, width, height, fps))
    {
        cout << "Failed to read video info\n";
        return;
    }

    FILE* pipe = open_ffmpeg_read_pipe(video_path);
    if (!pipe)
    {
        cout << "FFmpeg pipe failed\n";
        return;
    }

    unordered_map<string, int> line_memory;
    int line_counter = 1;
    vector<int> frame_start_lines;

    ofstream db(database_file, ios::app);

    vector<unsigned char> frame(width * height * 3);

    int frame_number = 0;

    while (true)
    {
        size_t read = fread(frame.data(), 1, frame.size(), pipe);
        if (read != frame.size()) break;

        frame_start_lines.push_back(line_counter);

        for (int y = 0; y < height; y++)
        {
            vector<unsigned char> row(frame.begin() + y * width * 3,
                frame.begin() + (y + 1) * width * 3);

            string key = row_to_key(row);

            if (line_memory.count(key))
            {
                db << line_counter << "=" << line_memory[key];
            }
            else
            {
                db << line_counter << "=" << key;
                line_memory[key] = line_counter;
            }

            if (y == 0) db << ",";
            else if (y == height - 1) db << ".";
            else db << ";";

            db << "\n";
            line_counter++;
        }

        frame_number++;
        cout << "Encoded Frame " << frame_number << "\n";
    }

    _pclose(pipe);
    db.close();

    string keyfile = video_path + "_KeyCode.txt";
    ofstream kf(keyfile);

    kf << "FPS: " << fps << "\n";
    kf << "Width: " << width << "\n";
    kf << "Height: " << height << "\n";
    kf << "Sequence: ";

    for (size_t i = 0; i < frame_start_lines.size(); i++)
    {
        kf << frame_start_lines[i];
        if (i + 1 < frame_start_lines.size()) kf << ",";
    }

    kf << "\n";
    kf.close();

    cout << "Encoding Complete\n";
}

/* ================= DECODE ================= */

void decode_video()
{
    string keyfile;
    cout << "Enter Key Code File Name: ";
    getline(cin, keyfile);

    ifstream kf(keyfile);
    if (!kf.is_open())
    {
        cout << "Key file not found\n";
        return;
    }

    int fps = 24, width = 0, height = 0;
    vector<int> sequence;

    string line;
    while (getline(kf, line))
    {
        if (line.rfind("FPS:", 0) == 0) fps = stoi(line.substr(4));
        else if (line.rfind("Width:", 0) == 0) width = stoi(line.substr(6));
        else if (line.rfind("Height:", 0) == 0) height = stoi(line.substr(7));
        else if (line.rfind("Sequence:", 0) == 0)
        {
            string nums = line.substr(9);
            stringstream ss(nums);
            string n;
            while (getline(ss, n, ',')) sequence.push_back(stoi(n));
        }
    }
    kf.close();

    ifstream db(database_file);
    if (!db.is_open())
    {
        cout << "Database not found\n";
        return;
    }

    unordered_map<int, string> db_lines;
    int max_line_number = 0;
    while (getline(db, line))
    {
        size_t eq = line.find('=');
        if (eq == string::npos) continue;

        int num = stoi(line.substr(0, eq));
        string value = line.substr(eq + 1);

        if (!value.empty() && (value.back() == ',' || value.back() == ';' || value.back() == '.'))
            value.pop_back();

        db_lines[num] = value;

        if (num > max_line_number)
            max_line_number = num;
    }
    db.close();

    string output = "Decoded_Output.mp4";
    FILE* pipe = open_ffmpeg_write_pipe(output, width, height, fps);

    if (!pipe)
    {
        cout << "Failed to open FFmpeg write pipe\n";
        return;
    }

    vector<unsigned char> frame(width * height * 3);

    for (size_t i = 0; i < sequence.size(); i++)
    {
        int start = sequence[i];
        int end = (i + 1 < sequence.size())
            ? sequence[i + 1]
            : (max_line_number + 1);

        int y = 0;

        for (int lineNum = start; lineNum < end; lineNum++)
        {
            if (!db_lines.count(lineNum)) continue;

            string data = db_lines[lineNum];

            if (data.find(',') == string::npos)
                data = db_lines[stoi(data)];

            stringstream ss(data);
            string val;

            int x = 0;
            while (getline(ss, val, ','))
            {
                frame[y * width * 3 + x] = (unsigned char)stoi(val);
                x++;
            }
            y++;
        }

        fwrite(frame.data(), 1, frame.size(), pipe);

        cout << "Decoded Frame " << (i + 1) << "/" << sequence.size() << "\n";
    }

    _pclose(pipe);

    cout << "Decoding Complete → " << output << "\n";
}

/* ================= MAIN ================= */

int main()
{
    cout << "1. Encode Video\n2. Decode Video\nChoice: ";

    int c;
    cin >> c;
    cin.ignore();

    if (c == 1) encode_video();
    else if (c == 2) decode_video();
    else cout << "Invalid choice\n";

    return 0;
}

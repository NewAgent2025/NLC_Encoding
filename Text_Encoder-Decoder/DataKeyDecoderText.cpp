#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <sys/stat.h> // for mkdir
#include <cstdlib>    // for exit

#ifdef _WIN32
#include <direct.h>   // for _mkdir on Windows
#endif

// Check If File Exists
bool fileExists(const std::string& filename) {
    std::ifstream f(filename.c_str());
    return f.good();
}

// Check If Directory Exists
bool directoryExists(const std::string& dirName) {
    struct stat info;
    if (stat(dirName.c_str(), &info) != 0) return false;
    return (info.st_mode & S_IFDIR) != 0;
}

// Create Directory If It Doesn't Exist
void createDirectory(const std::string& dirName) {
    if (!directoryExists(dirName)) {
#ifdef _WIN32
        _mkdir(dirName.c_str());
#else
        mkdir(dirName.c_str(), 0777);
#endif
    }
}

// Generate Page Code String From Text (Each Character's Positions On A Separate Line)
std::string generatePageCode(const std::string& text) {
    std::map<std::string, std::vector<int>> charPositions;

    for (size_t i = 0; i < text.size(); ++i) {
        std::string key;
        if (text[i] == '\n') key = "\\n";
        else key = std::string(1, text[i]);
        charPositions[key].push_back(static_cast<int>(i + 1));
    }

    std::ostringstream oss;
    for (auto it = charPositions.begin(); it != charPositions.end(); ++it) {
        oss << it->first << "=";
        const std::vector<int>& positions = it->second;
        for (size_t i = 0; i < positions.size(); ++i) {
            oss << positions[i];
            if (i != positions.size() - 1) oss << ",";
        }
        oss << "\n";
    }

    return oss.str();
}

// Save Page Code To Numbered File In Pages/Folder
int savePageCode(const std::string& pageCode) {
    std::string folder = "Pages";
    createDirectory(folder); // Ensure Folder Exists

    int pageNumber = 1;
    while (true) {
        std::string pageFile = folder + "/" + std::to_string(pageNumber);

        if (fileExists(pageFile)) {
            std::ifstream existingFile(pageFile);
            std::string existingCode((std::istreambuf_iterator<char>(existingFile)),
                std::istreambuf_iterator<char>());
            existingFile.close();

            if (existingCode == pageCode) {
                return pageNumber; // Duplicate Found, Reuse This Page Number
            }
            pageNumber++;
        }
        else {
            std::ofstream outFile(pageFile);
            outFile << pageCode;
            outFile.close();
            return pageNumber;
        }
    }
}

// Remove Extension From File Name
std::string removeExtension(const std::string& filename) {
    size_t lastDot = filename.find_last_of(".");
    if (lastDot == std::string::npos) return filename;
    return filename.substr(0, lastDot);
}

// Encode Text File
void encode() {
    std::string inputFile;
    std::cout << "Enter Text File Name To Encode: ";
    std::cin >> inputFile;

    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed To Open File.\n";
        return;
    }

    std::string text, line;
    while (std::getline(file, line)) {
        text += line + "\n";
    }
    file.close();

    std::string pageCode = generatePageCode(text);
    int pageNumber = savePageCode(pageCode);

    std::string baseName = removeExtension(inputFile);
    std::string outputFile = baseName + "_EncodedTXT.nlc";
    std::ofstream out(outputFile.c_str());
    out << pageNumber;
    out.close();

    std::cout << "Text Encoded Saved As: " << outputFile << " (Page #" << pageNumber << ")\n";
}

// Decode .nlc File
void decode() {
    std::string encodedFile;
    std::cout << "Enter Encoded File (.nlc) To Decode: ";
    std::cin >> encodedFile;

    std::ifstream file(encodedFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed To Open File.\n";
        return;
    }

    int pageNumber;
    file >> pageNumber;
    file.close();

    std::string pageFile = "Pages/" + std::to_string(pageNumber);
    if (!fileExists(pageFile)) {
        std::cerr << "Page Code File " << pageFile << " Not Found.\n";
        return;
    }

    std::ifstream page(pageFile.c_str());
    std::string line;
    std::map<std::string, std::vector<int>> charPositions;

    while (std::getline(page, line)) {
        if (line.empty()) continue;
        size_t eqPos = line.find('=');
        if (eqPos == std::string::npos) continue;

        std::string key = line.substr(0, eqPos);
        std::string positionsStr = line.substr(eqPos + 1);
        if (!positionsStr.empty() && positionsStr.back() == '.') positionsStr.pop_back();

        std::vector<int> positions;
        std::stringstream ss(positionsStr);
        std::string num;
        while (std::getline(ss, num, ',')) positions.push_back(std::stoi(num));

        charPositions[key] = positions;
    }
    page.close();

    int totalSize = 0;
    for (auto& it : charPositions)
        for (int pos : it.second)
            if (pos > totalSize) totalSize = pos;

    std::string decodedText(totalSize, ' ');

    for (auto& it : charPositions) {
        std::string key = it.first;
        char ch = (key == "\\n") ? '\n' : key[0];
        for (int pos : it.second)
            decodedText[pos - 1] = ch;
    }

    std::string baseName = removeExtension(encodedFile);
    size_t encodedPos = baseName.rfind("_EncodedTXT");
    if (encodedPos != std::string::npos) baseName = baseName.substr(0, encodedPos);
    std::string outputFile = baseName + "_DecodedTXT.txt";

    std::ofstream out(outputFile.c_str());
    out << decodedText;
    out.close();

    std::cout << "Decoded Text Saved As: " << outputFile << "\n";
}

int main() {
    std::cout << "Choose An Option:\n1. Encode\n2. Decode\nYour Choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) encode();
    else if (choice == 2) decode();
    else std::cout << "Invalid Choice.\n";

    return 0;
}

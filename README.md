# NLC Encoding/Decoding

**NLC Encoding/Decoding** is a program I have developed over the past **2 years** of hard work.  

It can **make any file into a smaller size using encoded output**. This works for:

- Images  
- Videos  
- Text  
- Audio  
- ZIPs  
- And more  

**Important:** To decode back to normal, you **must have a key code and the metadata**. Without the metadata, decoding is **useless and impossible**.  

This is a project I worked on after trying many methods to compress or encode files to smaller sizes.
#I Have Tested Many Methods Over The Years It Was One Of The Hardest Projects I Have Done
---

- Seems reversible but finding the exact seed impossible.  
- Decoding fast, but number bigger than original data.  
<details>
<summary><strong>Method 1 – Adding Up Numbers</strong></summary>

Adding up numbers doesn’t work. Example:  

- Hi = 34 + 9 = 43  
- iH can be 43 as well.  

Even with 2 numbers it’s impossible to decode back to normal. When encoding/compressing, you will have a lot of data.  

- Example: 4+3 = 7, 5+2 = 7, 1+6 = 7 → multiple results, impossible to decode.  
- Even using hashing like 1+6, 5+5, 6+9 = 2372 → hash cannot be undone.  

**Skipped.**

</details>

<details>
<summary><strong>Method 2 – Hashing Functions For Binary Code</strong></summary>

- Impossible to get data back.  
- Brute force would take extremely long.  
- Metadata doesn’t help.  

**Skipped.**

</details>

<details>
<summary><strong>Method 3 – Making Binary Code Shorter (64 bits)</strong></summary>

- Tried shortening all 64-bit sequences.  
- 64 bits = 3 bytes, output was 6–8 bytes → bigger than normal.  

**Skipped.**

</details>

<details>
<summary><strong>Method 4 – Adding Binary Code Numbers To Decode Later</strong></summary>

- Same issue as adding numbers → impossible.  

**Skipped.**

</details>

<details>
<summary><strong>Method 5 – All Binary Codes Of 21 Bits In A Notepad</strong></summary>

- Couldn’t have short pointers even when updating code.  

**Skipped.**

</details>

<details>
<summary><strong>Method 6 – Procedural Generation</strong></summary>

- Idea: Binary code → seed for procedural generation.  
- Example:  

- 101010011111010101010101000100101011010101111000001010101010101010101010101011111111010010101 = 2378213123

- Seems reversible but finding the exact seed impossible.  
- Decoding fast, but number bigger than original data.  

**Skipped.**

</details>

<details>
<summary><strong>Method 7 – Hashing a File and Brute Force Recovery</strong></summary>

- Impossible due to collisions of data.  
- Data to recover would be huge.  
<details>
<summary><strong>Method 1 – Adding Up Numbers</strong></summary>

Adding up numbers doesn’t work. Example:  

- Hi = 34 + 9 = 43  
- iH can be 43 as well.  

Even with 2 numbers it’s impossible to decode back to normal. When encoding/compressing, you will have a lot of data.  

- Example: 4+3 = 7, 5+2 = 7, 1+6 = 7 → multiple results, impossible to decode.  
- Even using hashing like 1+6, 5+5, 6+9 = 2372 → hash cannot be undone.  

**Skipped.**

</details>

<details>
<summary><strong>Method 2 – Hashing Functions For Binary Code</strong></summary>

- Impossible to get data back.  
- Brute force would take extremely long.  
- Metadata doesn’t help.  

**Skipped.**

</details>

<details>
<summary><strong>Method 3 – Making Binary Code Shorter (64 bits)</strong></summary>

- Tried shortening all 64-bit sequences.  
- 64 bits = 3 bytes, output was 6–8 bytes → bigger than normal.  

**Skipped.**

</details>

<details>
<summary><strong>Method 4 – Adding Binary Code Numbers To Decode Later</strong></summary>

- Same issue as adding numbers → impossible.  

**Skipped.**

</details>

<details>
<summary><strong>Method 5 – All Binary Codes Of 21 Bits In A Notepad</strong></summary>

- Couldn’t have short pointers even when updating code.  

**Skipped.**

</details>

<details>
<summary><strong>Method 6 – Procedural Generation</strong></summary>

- Idea: Binary code → seed for procedural generation.  
- Example:
- 101010011111010101010101000100101011010101111000001010101010101010101010101011111111010010101 = 2378213123

- Seems reversible but finding the exact seed impossible.  
- Decoding fast, but number bigger than original data.  

**Skipped.**

</details>
**Skipped.**
</details>

<details>
<summary><strong>Method 8 – Shorter Pointers With Big Data</strong></summary>

- Tried encoding zeros and ones as AB, BA, BB, AA.  
- Cannot encode all sequences.  

**Skipped.**
</details>

<details>
<summary><strong>Method 9 – Binary Code as One Character</strong></summary>

- Example: 1 = A, 0 = AA, 10 = AAA  
- Output would be massive (1 MB → 12 MB).  

**Skipped.**
</details>

<details>
<summary><strong>Method 10 – Delta Encoding Positions</strong></summary>

- Example positions: 1,32,31,23,12,315,43,64,5,234,234,478,5678,545,2,3265,4567,567,45  
- Delta encoding → 1 -120, etc. → output bigger or same.  

**Skipped.**
</details>

<details>
<summary><strong>Method 11 – Word Encoding</strong></summary>

- Example: Hello → Hel = 12, lo = 17  
- Encoding with Unicode emojis, A-Z, a-z → output bigger.  

**Skipped.**
</details>

<details>
<summary><strong>Method 12 – Compress Data Inside QR Code</strong></summary>

- Tried compressing copies of same data.  

**Skipped.**
</details>

<details>
<summary><strong>Method 13 – Uploading Online</strong></summary>

- Skipped because fake and cheating.  
</details>

<details>
<summary><strong>Method 14 – Image With All Binary Code</strong></summary>

- Output bigger than normal.  

**Skipped.**
</details>

<details>
<summary><strong>Method 15 – New Base Encoding</strong></summary>

- Data not really changed.  

**Skipped.**
</details>

<details>
<summary><strong>Method 16 – Self-Updating Binary Code System</strong></summary>

- Table got bigger, system no longer worked.  

**Skipped.**
</details>

<details>
<summary><strong>Method 17 – All Binary Code Inside 1 EXE</strong></summary>

- Pointers inside EXE → impossible to point to bigger data with short number.  
- HEX encoding → same problem.  

**Skipped.**
</details>

<details>
<summary><strong>Method 18 – Adding Numbers To Compress</strong></summary>

- Example: 234,639 + 344,621 = 579,260  
- Needed sum + middle + last numbers → output bigger.  
- Before: 234639344621 = 12 long  
- After: 5792604976 = 10 long → not effective  

**Skipped.**
</details>

<details>
<summary><strong>Method 19 – Run Length Encoding</strong></summary>

- Didn’t save space.  

**Skipped.**
</details>

<details>
<summary><strong>Method 20 – Deduplication Using Positions</strong></summary>

- Position encoding problem → impossible.  

**Skipped.**
</details>

<details>
<summary><strong>Method 21 – Checksum / Fingerprint / Hashing</strong></summary>

- Cannot reconstruct original file.  

**Skipped.**
</details>

<details>
<summary><strong>Method 22 – Character Count + Unique Hash</strong></summary>

- Example: 0 = 523, 1 = 1042, hash = ash45ru90sfdj08w34j53e48r09nfsdk843590  
- Cannot decode.  

**Skipped.**
</details>

<details>
<summary><strong>Method 23 – Adding Data Inside Images</strong></summary>

- Compression loses data.  

**Skipped.**
</details>

<details>
<summary><strong>Method 24 – Making Positions Into Small Numbers</strong></summary>

- Example: positions 1,5,8,11,14,17 → 1,2,2,2,1,2,1,2,2,2,1  
- Encoding → sometimes wrong positions.  

**Skipped.**
</details>

<details>
<summary><strong>Method 25 – Only Encoding Used Characters</strong></summary>

- Metadata required → text could become bigger.  

**Skipped.**
</details>

<details>
<summary><strong>Method 26 – Binary Encoding 25 Bits, Short Codes</strong></summary>

- Saved used bits → replaced with short codes.  
- Output bigger, metadata needed.  

**Skipped.**
</details>

<details>
<summary><strong>Method 27 – Crack File Using Few Bits</strong></summary>

- Example 4-bit sequences: 0000, 0001, etc.  
- Output bigger, decoding impossible.  

**Skipped.**
</details>

<details>
<summary><strong>Method 28 – 4096-Bit Encoding / Lookup</strong></summary>

- Tried encoding 4096 bits → metadata required, lookup table huge.  

**Skipped.**
</details>

<details>
<summary><strong>Method 29 – Encoding Binary Code To 94 Characters</strong></summary>

- A-Z, a-z, 0-9, symbols → bytes look smaller but total size bigger.  

**Skipped.**
</details>

<details>
<summary><strong>Method 30 – Reencode 2 Bytes Per Chunk</strong></summary>

- Needed metadata → took lots of space.  

**Skipped.**
</details>

<details>
<summary><strong>Method 31 – Word Encoding + Hash/Procedural Generation</strong></summary>

- Words saved + hash/seed → metadata required  
- Typo or wrong sequence → decoding impossible.  

**Skipped.**
</details>

<details>
<summary><strong>Method 32 – EXE to Load Numbers/Binary Code</strong></summary>

- Like KKrieg or DirectX procedural generation  
- Did not reduce size.  

**Skipped.**
</details>

<details>
<summary><strong>Method 33 – EXEs With Binary Code For Decoding</strong></summary>

- Too many EXEs, too many 25-bit sequences → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 34 – Binary Encoding 25 Bits + Shorter Bits</strong></summary>

- Saved used bits → replaced with shorter bits  
- Metadata required, decoding impossible  
- Encoded file looks smaller, but cannot decode back.  

**Skipped.**
</details>
<details>
<summary><strong>Method 35 – Differential Bit Masking</strong></summary>

- Idea: Mask common bit patterns to save space.  
- Issue: Masking requires metadata for decoding → often bigger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 36 – Huffman Tree Compression on Substrings</strong></summary>

- Idea: Build Huffman trees for small repeating substrings.  
- Issue: Metadata for each substring → output larger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 37 – Arithmetic Coding on Nibble Pairs</strong></summary>

- Idea: Encode 4-bit pairs as fractional numbers.  
- Issue: Precision needed for decoding → ends up larger.  

**Skipped.**
</details>

<details>
<summary><strong>Method 38 – Frequency-Ordered Base Conversion</strong></summary>

- Idea: Map most frequent bytes to smaller bases.  
- Issue: Base mapping metadata → bigger output than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 39 – Chunk Deduplication Across Files</strong></summary>

- Idea: Reuse common chunks across files to save space.  
- Issue: Requires full index of chunks → metadata outweighs gains.  

**Skipped.**
</details>

<details>
<summary><strong>Method 40 – Bit Folding + XOR</strong></summary>

- Idea: Fold binary sequences and XOR to reduce size.  
- Issue: Folding + XOR info needed to decode → no compression.  

**Skipped.**
</details>

<details>
<summary><strong>Method 41 – Modular Compression</strong></summary>

- Idea: Store bytes modulo a smaller number to shrink size.  
- Issue: Modulo loses information → impossible to reconstruct.  

**Skipped.**
</details>

<details>
<summary><strong>Method 42 – Entropy Pooling</strong></summary>

- Idea: Combine high-entropy sections to compress.  
- Issue: Combining requires extra offsets → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 43 – Symbolic Pattern Mapping</strong></summary>

- Idea: Map frequent byte patterns to symbols.  
- Issue: Symbol table metadata → output larger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 44 – Multi-Layer Delta Encoding</strong></summary>

- Idea: Take differences multiple times to shrink positions.  
- Issue: Negative numbers and metadata → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 45 – Recursive Binary Packing</strong></summary>

- Idea: Pack bits recursively into smaller groups.  
- Issue: Recursion metadata → total file bigger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 46 – Pseudo-Random Re-Ordering</strong></summary>

- Idea: Shuffle bits using PRNG and save seed.  
- Issue: Seed + reordering metadata → bigger output than file.  

**Skipped.**
</details>

<details>
<summary><strong>Method 47 – Phase Encoding</strong></summary>

- Idea: Map binary values to phases (0°, 90°, 180°, 270°).  
- Issue: Storing phases digitally → more bytes than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 48 – Delta-of-Hashes</strong></summary>

- Idea: Encode differences between hashes of sections.  
- Issue: Hashes still large → output larger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 49 – Multi-Base Fibonacci Encoding</strong></summary>

- Idea: Map data to Fibonacci numbers in multiple bases.  
- Issue: Number growth + metadata → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 50 – Layered Run-Length Encoding</strong></summary>

- Idea: Apply RLE in layers of different chunk sizes.  
- Issue: Layering adds metadata → bigger file.  

**Skipped.**
</details>

<details>
<summary><strong>Method 51 – Binary Graph Mapping</strong></summary>

- Idea: Represent bits as nodes in a graph.  
- Issue: Graph storage → output larger than input.  

**Skipped.**
</details>

<details>
<summary><strong>Method 52 – Bit-Interleaving Encoding</strong></summary>

- Idea: Interleave bits from multiple bytes to save space.  
- Issue: Requires metadata for each byte → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 53 – Run-Length + Entropy Hybrid</strong></summary>

- Idea: Compress runs with entropy coding.  
- Issue: Metadata often > space saved → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 54 – Sparse Bit-Plane Encoding</strong></summary>

- Idea: Encode only significant bit planes.  
- Issue: Need to store ignored planes → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 55 – Binary Graphical Encoding</strong></summary>

- Idea: Represent bits as pixels in images for compression.  
- Issue: Image storage often larger than file → no savings.  

**Skipped.**
</details>

<details>
<summary><strong>Method 56 – Adaptive Base Compression</strong></summary>

- Idea: Change base per chunk dynamically.  
- Issue: Base info metadata → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 57 – Polynomial Mapping</strong></summary>

- Idea: Encode sequences using polynomial equations.  
- Issue: Polynomials and coefficients → bigger output than file.  

**Skipped.**
</details>

<details>
<summary><strong>Method 58 – Multi-Stage Dictionary</strong></summary>

- Idea: Build multiple dictionaries for different file sections.  
- Issue: Dictionaries + pointers → bigger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 59 – Neural Network Prediction</strong></summary>

- Idea: Train network to predict next byte, store errors only.  
- Issue: Network + errors metadata → bigger output for most data.  

**Skipped.**
</details>

<details>
<summary><strong>Method 60 – Probabilistic Bit Masking</strong></summary>

- Idea: Mask bits probabilistically for compression.  
- Issue: Mask patterns must be stored → bigger than original.  

**Skipped.**
</details>

<details>
<summary><strong>Method 61 – Modular Bit Packing</strong></summary>

- Idea: Pack bits modulo a smaller group size.  
- Issue: Modulo info required to decode → no gain.  

**Skipped.**
</details>

<details>
<summary><strong>Method 62 – Delta Encoding With Skip Values</strong></summary>

- Idea: Encode differences with skips for zeros.  
- Issue: Skip metadata → output bigger than file.  

**Skipped.**
</details>

<details>
<summary><strong>Method 63 – Symbolic Substitution</strong></summary>

- Idea: Replace frequent bytes with symbols from Unicode.  
- Issue: Unicode symbols often larger than byte → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 64 – Layered Bit Folding</strong></summary>

- Idea: Fold bits multiple times for compression.  
- Issue: Folding info required to decode → bigger output.  

**Skipped.**
</details>

<details>
<summary><strong>Method 65 – Bitwise Rotational Mapping</strong></summary>

- Idea: Rotate bits and store rotation sequence.  
- Issue: Rotation sequence metadata → file bigger.  

**Skipped.**
</details>

---

**Conclusion:**  

After 2 years and **65 methods+**, almost all approaches failed. Most failed due to:

- Metadata requirements  
- Output bigger than original  
- Impossible decoding  

**NLC Encoding/Decoding** now only works with **key code + metadata** to recover files. Without metadata, decoding is **useless and impossible**.

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

---

## Everything I Know About Trying To Compress/Encode Data To A Smaller Size

Below are **all 34 methods I tried**, exactly as I did them, with explanations why they were skipped or failed.  

<details>
<summary>Method 1 – Adding Up Numbers</summary>

- Hi = 34 + 9 = 43  
- iH can also be 43. Multiple sequences give the same sum.  
- Example: 4+3 = 7, 5+2 = 7, 1+6 = 7 → impossible to decode.  
- Even using a hash function like 1+6, 5+5, 6+9 = 2372 → cannot be undone.  
- **Skipped.**
</details>

<details>
<summary>Method 2 – Hashing Functions for Binary Code</summary>

- Impossible to get data back.  
- Brute force would take super long.  
- Metadata doesn’t help.  
- **Skipped.**
</details>

<details>
<summary>Method 3 – Shortening Binary Code (64 bits)</summary>

- Tried making all 64-bit sequences shorter.  
- 64 bits = 3 bytes, output became 6–8 bytes → bigger than normal data.  
- **Skipped.**
</details>

<details>
<summary>Method 4 – Adding Binary Code Numbers to Decode Later</summary>

- Same issue as adding numbers → impossible to decode.  
- **Skipped.**
</details>

<details>
<summary>Method 5 – All 21-bit Binary Codes in a Notepad</summary>

- Tried storing all 21-bit codes in a notepad to decode later.  
- Cannot have short pointers even when updating the code.  
- **Skipped.**
</details>

<details>
<summary>Method 6 – Procedural Generation</summary>

- Idea: Convert binary code to seed for procedural generation.  
- Example:  
  101010011111010101010101000100101011010101111000001010101010101010101010101011111111010010101 = 2378213123  
- Seems possible to get it back, but finding the exact seed is impossible.  
- Decoding might be fast, but number likely bigger than original data.  
- **Skipped.**
</details>

<details>
<summary>Method 7 – Hashing a File and Brute Force Recovery</summary>

- Hash a file, then try to brute-force decode it back.  
- Impossible due to data collisions.  
- Data to get back would be extremely large.  
- **Skipped.**
</details>

<details>
<summary>Method 8 – Shorter Pointers with Big Data</summary>

- Tried encoding zeros and ones as AB, BA, BB, AA.  
- Not all sequences can be encoded.  
- **Skipped.**
</details>

<details>
<summary>Method 9 – Binary Code as One Character</summary>

- Example: 1 = A, 0 = AA, 10 = AAA  
- Output becomes huge → 1 MB file → 12 MB.  
- **Skipped.**
</details>

<details>
<summary>Method 10 – Delta Encoding Positions</summary>

- Example: 1,32,31,23,12,315,43,64,5,234,234,478,5678,545,2,3265,4567,567,45  
- Delta encoding produces 1 -120 → useless.  
- Output bigger than original.  
- **Skipped.**
</details>

<details>
<summary>Method 11 – Word Encoding</summary>

- Example: Hello → Hel = 12, lo = 17  
- Encoding with Unicode emojis, A-Z, a-z → output bigger.  
- **Skipped.**
</details>

<details>
<summary>Method 12 – Compressing in QR Code</summary>

- Tried compressing copies of data in QR code.  
- Didn’t work.  
- **Skipped.**
</details>

<details>
<summary>Method 13 – Uploading Online</summary>

- Skipped because fake and cheating.  
</details>

<details>
<summary>Method 14 – Image with All Binary Code</summary>

- Output bigger than normal data.  
- **Skipped.**
</details>

<details>
<summary>Method 15 – New Base Encoding</summary>

- Data wasn’t really changed.  
- **Skipped.**
</details>

<details>
<summary>Method 16 – Self Updating Binary Code System</summary>

- Table became bigger → system no longer worked.  
- **Skipped.**
</details>

<details>
<summary>Method 17 – All Binary Code in One EXE</summary>

- Tried pointers inside EXE to bigger data.  
- HEX encoding / pointers → output bigger.  
- **Skipped.**
</details>

<details>
<summary>Method 18 – Adding Numbers for Compression</summary>

- Example: 234,639 + 344,621 = 579,260  
- Would need sum, first/middle/last numbers → output bigger.  
- Before: 234639344621 = 12 long  
- After: 5792604976 = 10 long → doesn’t really save space.  
- **Skipped.**
</details>

<details>
<summary>Method 19 – Run Length Encoding</summary>

- Didn’t save space.  
- **Skipped.**
</details>

<details>
<summary>Method 20 – Deduplication Using Positions</summary>

- Position encoding problems → impossible.  
- **Skipped.**
</details>

<details>
<summary>Method 21 – Checksum / Fingerprint / Hashing</summary>

- Cannot reconstruct original file.  
- **Skipped.**
</details>

<details>
<summary>Method 22 – Character Count + Unique Hash</summary>

- Example: 0=523, 1=1042, Hash=ash45ru90sfdj08w34j53e48r09nfsdk843590  
- Cannot decode.  
- **Skipped.**
</details>

<details>
<summary>Method 23 – Adding Data Inside Images</summary>

- Compressed image loses data.  
- **Skipped.**
</details>

<details>
<summary>Method 24 – Small Numbers for Positions</summary>

- Example: positions 1,5,8,11,14,17 → 1,2,2,2,1,2,1,2,2,2,1  
- Encoding sum/hash → sometimes wrong positions, failed.  
- **Skipped.**
</details>

<details>
<summary>Method 25 – Only Encoding Used Characters</summary>

- Need metadata → output bigger.  
- **Skipped.**
</details>

<details>
<summary>Method 26 – Binary Encoding 25 Bits, Short Codes</summary>

- Saved used bits and replaced with short codes.  
- Output bigger, metadata required.  
- **Skipped.**
</details>

<details>
<summary>Method 27 – Crack File Using Few Bits</summary>

- 4-bit sequences → 00, 01, 10, 11  
- Output bigger, impossible to decode.  
- **Skipped.**
</details>

<details>
<summary>Method 28 – 4096-Bit Encoding / Lookup</summary>

- Tried encoding 4096 bits → metadata required, lookup table huge.  
- **Skipped.**
</details>

<details>
<summary>Method 29 – Binary to 94 Characters</summary>

- Encoding to A-Z, a-z, 0-9, symbols → output bigger.  
- **Skipped.**
</details>

<details>
<summary>Method 30 – Reencode 2 Bytes per Chunk</summary>

- Needed metadata → took lots of space.  
- **Skipped.**
</details>

<details>
<summary>Method 31 – Word Encoding + Hash/Seed</summary>

- Words + procedural generation → metadata required  
- Typo or wrong sequence → decoding impossible.  
- **Skipped.**
</details>

<details>
<summary>Method 32 – EXE to Load Numbers / Binary Code</summary>

- Like KKrieg or DirectX procedural generation  
- Did not reduce size for arbitrary files.  
- **Skipped.**
</details>

<details>
<summary>Method 33 – EXEs Holding 25 Bits for Decoding</summary>

- Too many EXEs, too many 25-bit sequences → bigger output.  
- **Skipped.**
</details>

<details>
<summary>Method 34 – 25-Bit Encoding with Shorter Bits</summary>

- Saved used bits, replaced with shorter bits  
- Metadata required, decoding impossible  
- Encoded file looks smaller, but cannot decode back.  
- **Skipped.**
</details>

---

## Conclusion

- After **2 years** and **34 methods**, nearly all approaches to reversible compression failed.  
- Many methods worked **theoretically**, but failed due to:  
  - Metadata requirements  
  - Output bigger than original  
  - Impossible decoding  
- The project now successfully **encodes any file**, and decoding is **only possible with key code + metadata**.  

---

**NLC Encoding/Decoding** is a **secure, metadata-protected file encoding system** built from years of experimentation.


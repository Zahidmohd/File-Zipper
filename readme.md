# Huffman Coding File Compressor

## Overview
This project implements a file compression and decompression tool using the Huffman coding algorithm. It provides an efficient, lossless method for reducing file sizes, making it useful for storage optimization and data transmission.

## Features
- Lossless compression of text files
- Decompression of files compressed with this tool
- Command-line interface for easy use
- Efficient implementation of Huffman coding algorithm

## Requirements
- C++ compiler (C++11 or later)
- Standard C++ libraries

## Installation
1. Clone the repository: 
git clone https://github.com/Zahidmohd/File-Zipper.git
2. Navigate to the project directory: cd foldername(folder in which you have clone it).
3. Compile the project: g++ -std=c++11 main.cpp huffman.cpp compress.cpp decompress.cpp -o huffman_compressor
## Usage
- To compress a file: ./huffman_compressor c input.txt compressed.bin
- To decompress a file:./huffman_compressor d compressed.bin decompressed.txt 
## Testing and Verification

- ### Generating Test Files
  - You can generate test files of any size using the provided Python script: python create_test_file.py <filename>(take name as "input.txt" as i have code for the same) <size_in_kb>
  - Example: python create_test_file.py input.txt 100
This will create a 100 KB file named `input.txt`.

- ### Compression and Decompression Test

  1. Compress the test file:
  `./huffman_compressor c input.txt compressed.bin`
  2. Decompress the file:
  `./huffman_compressor d compressed.bin decompressed.txt`
  3. Compare the original and decompressed files to verify the process:
`diff test_input.txt decompressed.txt`
  4. If there's no output, the files are identical.
- ### File Comparison with bsdiff4

  - For a more advanced file comparison and patch generation, you can use the bsdiff4 algorithm. Check out my [bsdiff4 repository](https://github.com/Zahidmohd/bsdiff4) for implementation details and usage instructions.

  - Using bsdiff4, you can:
    1.  Generate a patch between the original and compressed files.
    2.  Apply the patch to verify the integrity of the compression/decompression process.

  - This provides an additional layer of verification for the Huffman coding implementation.
## How It Works
1. The compressor reads the input file and counts the frequency of each character.
2. It builds a Huffman tree based on these frequencies.
3. The tree is used to generate unique binary codes for each character.
4. The text is encoded using these codes, and the compressed data is written to a file along with the frequency table.
5. For decompression, the process is reversed using the stored frequency table.

## Project Structure
- `main.cpp`: Entry point of the program
- `huffman.h`: Header file with Huffman coding class and structure declarations
- `huffman.cpp`: Implementation of Huffman coding algorithm
- `compress.cpp`: File compression function
- `decompress.cpp`: File decompression function
- `create_test_file`: File creation function for testing if required

## Contributing
Contributions, issues, and feature requests are welcome. Feel free to check [issues page](https://github.com/Zahidmohd/File-Zipper/issues) if you want to contribute.


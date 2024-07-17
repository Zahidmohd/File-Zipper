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
1. Clone the repository: git clone https://github.com/Zahidmohd/File-Zipper.git
2. Navigate to the project directory: cd foldername(folder in which you have clone it).
3. Compile the project: g++ -std=c++11 main.cpp huffman.cpp compress.cpp decompress.cpp -o huffman_compressor
## Usage
To compress a file: ./huffman_compressor c input.txt compressed.bin
To decompress a file:./huffman_compressor d compressed.bin decompressed.txt 
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

## Contributing
Contributions, issues, and feature requests are welcome. Feel free to check [issues page](https://github.com/Zahidmohd/File-Zipper/issues) if you want to contribute.


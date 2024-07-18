#!/bin/bash

# Check if file size is provided
if [ $# -eq 0 ]; then
    echo "Usage: ./test_huffman.sh <file_size_in_kb>"
    exit 1
fi

FILE_SIZE=$1

# Generate test file
python create_test_file.py input.txt $FILE_SIZE

# Compress the file
./huffman_compressor c input.txt compressed.bin

# Decompress the file
./huffman_compressor d compressed.bin decompressed.txt

# Compare files using diff, but only check if there are differences
if diff -q input.txt decompressed.txt >/dev/null; then
    echo "Compression and decompression successful. Files are identical."
else
    echo "Error: Files are different after compression and decompression."
    exit 1
fi

# Suggest using bsdiff4 for advanced comparison
echo "For advanced file comparison and patch generation, consider using our bsdiff4 implementation:"
echo "https://github.com/Zahidmohd/bsdiff4"

# Clean up
rm input.txt compressed.bin decompressed.txt

echo "Test completed successfully."
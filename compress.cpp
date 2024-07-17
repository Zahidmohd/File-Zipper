#include "huffman.h"
#include <fstream>

void compressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    std::string text((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    
    std::unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    Node* root = Huffman::buildHuffmanTree(freq);

    std::unordered_map<char, std::string> huffmanCode;
    Huffman::generateCodes(root, "", huffmanCode);

    std::string encodedText = Huffman::compress(text, huffmanCode);

    // Write frequency table
    int tableSize = freq.size();
    outFile.write(reinterpret_cast<const char*>(&tableSize), sizeof(int));
    for (const auto& pair : freq) {
        outFile.write(&pair.first, sizeof(char));
        outFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(int));
    }

    // Write encoded text
    int encodedSize = encodedText.length();
    outFile.write(reinterpret_cast<const char*>(&encodedSize), sizeof(int));
    
    // Write encoded text bit by bit
    char byte = 0;
    int bitCount = 0;
    for (char bit : encodedText) {
        byte = (byte << 1) | (bit - '0');
        bitCount++;
        if (bitCount == 8) {
            outFile.write(&byte, sizeof(char));
            byte = 0;
            bitCount = 0;
        }
    }
    if (bitCount > 0) {
        byte <<= (8 - bitCount);
        outFile.write(&byte, sizeof(char));
    }

    inFile.close();
    outFile.close();
}
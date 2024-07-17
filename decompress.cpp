#include "huffman.h"
#include <fstream>

void decompressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    // Read frequency table
    int tableSize;
    inFile.read(reinterpret_cast<char*>(&tableSize), sizeof(int));

    std::unordered_map<char, int> freq;
    for (int i = 0; i < tableSize; i++) {
        char c;
        int f;
        inFile.read(&c, sizeof(char));
        inFile.read(reinterpret_cast<char*>(&f), sizeof(int));
        freq[c] = f;
    }

    Node* root = Huffman::buildHuffmanTree(freq);

    // Read encoded text
    int encodedSize;
    inFile.read(reinterpret_cast<char*>(&encodedSize), sizeof(int));

    std::string encodedText = "";
    char byte;
    while (inFile.read(&byte, sizeof(char))) {
        for (int i = 7; i >= 0 && encodedText.length() < encodedSize; i--) {
            encodedText += ((byte >> i) & 1) ? '1' : '0';
        }
    }

    std::string decodedText = Huffman::decompress(encodedText, root);
    outFile << decodedText;

    inFile.close();
    outFile.close();
}
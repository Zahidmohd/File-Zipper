#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct Node {
    char character;
    int freq;
    Node *left, *right;

    Node(char c, int f) : character(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

class Huffman {
public:
    static Node* buildHuffmanTree(const std::unordered_map<char, int>& freq);
    static void generateCodes(Node* root, std::string code, std::unordered_map<char, std::string>& huffmanCode);
    static std::string compress(const std::string& text, const std::unordered_map<char, std::string>& huffmanCode);
    static std::string decompress(const std::string& encodedText, Node* root);
};

#endif
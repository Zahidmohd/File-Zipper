#include "huffman.h"

Node* Huffman::buildHuffmanTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    return pq.top();
}

void Huffman::generateCodes(Node* root, std::string code, std::unordered_map<char, std::string>& huffmanCode) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        huffmanCode[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

std::string Huffman::compress(const std::string& text, const std::unordered_map<char, std::string>& huffmanCode) {
    std::string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCode.at(c);
    }
    return encodedText;
}

std::string Huffman::decompress(const std::string& encodedText, Node* root) {
    std::string text = "";
    Node* current = root;
    
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            text += current->character;
            current = root;
        }
    }
    return text;
}
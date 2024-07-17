#include <iostream>
#include <string>

void compressFile(const std::string& inputFile, const std::string& outputFile);
void decompressFile(const std::string& inputFile, const std::string& outputFile);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <mode> <input_file> <output_file>" << std::endl;
        std::cout << "Mode: 'c' for compress, 'd' for decompress" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    if (mode == "c") {
        compressFile(inputFile, outputFile);
        std::cout << "File compressed successfully." << std::endl;
    } else if (mode == "d") {
        decompressFile(inputFile, outputFile);
        std::cout << "File decompressed successfully." << std::endl;
    } else {
        std::cout << "Invalid mode. Use 'c' for compress or 'd' for decompress." << std::endl;
        return 1;
    }

    return 0;
}
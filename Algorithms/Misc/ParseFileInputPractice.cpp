#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream inputFile("input000.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    int numLines;
    inputFile >> numLines;

    std::vector<std::string> lines;
    std::string line;
    std::getline(inputFile, line);  // Consume the newline after numLines

    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    std::cout << "Number of lines: " << numLines << std::endl;
    for (const std::string& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}

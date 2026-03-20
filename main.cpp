#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uporaba: vaja2 <vhodna_datoteka>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        std::cout << "Napaka: datoteke ni mogoce odpreti." << std::endl;
        return 1;
    }

    std::vector<unsigned char> numbers;
    int temp;

    while (inputFile >> temp) {
        if (temp < 0 || temp > 255) {
            std::cout << "Napaka: stevilo izven obsega (0-255)" << std::endl;
            return 1;
        }
        numbers.push_back(static_cast<unsigned char>(temp));
    }

    std::cout << "Prebrana stevila:" << std::endl;
    for (unsigned char n : numbers) {
        std::cout << (int)n << " ";
    }
    std::cout << std::endl;

    inputFile.close();
    return 0;
}
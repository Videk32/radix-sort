#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uporaba: vaja2 <vhodna_datoteka>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::cout << "Vhodna datoteka: " << inputFilePath << std::endl;
    std::ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        std::cout << "Napaka: datoteke ni mogoce odpreti." << std::endl;
        return 1;
    }

    std::cout << "Datoteka uspešno odprta." << std::endl;

    return 0;
}
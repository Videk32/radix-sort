#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uporaba: vaja2 <vhodna_datoteka>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::cout << "Vhodna datoteka: " << inputFilePath << std::endl;

    return 0;
}
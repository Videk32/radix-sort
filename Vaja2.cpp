#include <iostream>
#include <fstream>
#include <vector>


void countingSortByBit(std::vector<unsigned char>& A, int k) {
    std::vector<unsigned char> B(A.size());
    int count[2] = {0, 0};

    for (unsigned char x : A) {
        int bit = (x >> k) & 1;
        count[bit]++;
    }

    count[1] += count[0];

    for (int i = static_cast<int>(A.size()) - 1; i >= 0; --i) {
        int bit = (A[i] >> k) & 1;
        B[--count[bit]] = A[i];
    }

    A = B;
}

void radixSort(std::vector<unsigned char>& A) {
    for (int k = 0; k < 8; k++) {
        countingSortByBit(A, k);
    }
}

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

    radixSort(numbers);

    std::ofstream outputFile("out.txt");

    if (!outputFile.is_open()) {
        std::cout << "Napaka: izhodne datoteke ni mogoce odpreti." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); i++) {
        outputFile << static_cast<int>(numbers[i]);
        if (i != numbers.size() - 1) {
            outputFile << " ";
        }
    }

    return 0;
}
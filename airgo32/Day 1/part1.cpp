#include <iostream>
#include <fstream>

int main() {
    int elves[3000];
    int i = 0;
    elves[i] = 0;
    int max = 0;
    
    std::ifstream inputfile;
    std::string line;
    inputfile.open("input.txt");

    while (std::getline (inputfile, line)) {
        if (line.empty()) {
            if (elves[i] > elves[max]) max = i;
            i++;
            elves[i] = 0;
        } else {
            elves[i] += stoi(line);
        }
    }

    std::cout << "Most calories: " << elves[max] <<
    "\n Elf: " << max << "\n";
}
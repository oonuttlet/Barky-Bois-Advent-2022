#include <iostream>
#include <fstream>

void swap_int(int * a, int * b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main() {
    int elves[3000];
    int i = 0;
    elves[i] = 0;
    int first = 0, second = 0, third = 0;
    
    std::ifstream inputfile;
    std::string line;
    inputfile.open("input.txt");

    while (std::getline (inputfile, line)) {
        if (line.empty()) {
            if (elves[i] > elves[third]) third = i;
            if (elves[third] > elves[second]) swap_int(&third, &second);
            if (elves[second] > elves[first]) swap_int(&second, &first);
            i++;
            elves[i] = 0;
        } else {
            elves[i] += stoi(line);
        }
    }

    std::cout << "Elf " << first << ": " << elves[first] << "\n";
    std::cout << "Elf " << second << ": " << elves[second] << "\n";
    std::cout << "Elf " << third << ": " << elves[third] << "\n";
}
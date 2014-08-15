/*
   Write a method to print the last K lines of an input file using C++.
*/

#include <string>
#include <iostream>
#include <fstream>

void printKLinesFromFile(int K, std::ifstream &ifs) 
{
    std::string arr[K];
    int total = 0;
    int i = 0;

    if (K <= 0 || !ifs.is_open()) return;

    while (!ifs.eof()) {
        std::string tmp;
        std::getline(ifs, tmp);
        if (ifs.eof()) break;
        arr[i] = tmp;
        total++;
        i = total % K;
    }

    if (total <= K) {
        for (int j = 0; j < i; j++) {
            std::cout << arr[j] << std::endl;
        }
    }
    else {
        for (int j = i; j < K; j++) {
            std::cout << arr[j] << std::endl;
        }
        for (int j = 0; j < i; j++) {
            std::cout << arr[j] << std::endl;
        }
    }
}
int main()
{
    std::ifstream ifs("1.txt");

    printKLinesFromFile(3, ifs);
}

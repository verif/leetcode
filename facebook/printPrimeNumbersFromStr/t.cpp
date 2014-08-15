/*
   print out all prime numbers in a given string. abc2134kd31 -> 2, 13, 3, 3
*/

#include <iostream>
#include <string> 
using namespace std;

class PrintPrime {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i*i <= num; i++) {
            if (!(num % i)) return false;
        }
        return true;
    }
    void printPrimeNumberFromDigits(string& digits) {
        for (int i = 0; i < digits.length(); i++) {
            for (int j = i; j < digits.length(); j++) {
                int num = atoi(digits.substr(i, j-i+1).c_str());
                if (isPrime(num)) cout << num << endl;
            }
        }
    }
    void printPrimeNumberFromString(string str) {
        int i = 0;
        int len = str.length();
        while (i < len) {
            string digits;
            while (i < len && !(str[i] >= '0' && str[i] <= '9')) i++;
            while (i < len && str[i] >= '0' && str[i] <= '9') {
                digits.push_back(str[i++]);
            }
            printPrimeNumberFromDigits(digits);
        }
    }
};

int main() {
    PrintPrime pp;
    string str = "abc2134kd31";

    cout << str << endl;
    pp.printPrimeNumberFromString(str);

    str = "123456789";
    cout << str << endl;
    pp.printPrimeNumberFromString(str);

    str = "abcdefg";
    cout << str << endl;
    pp.printPrimeNumberFromString(str);
}

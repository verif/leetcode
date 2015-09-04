/* Find all prime factors of an given integer */

#include <iostream>
using namespace std;

class PrimeFactor {
public:
    bool isPrime(int v) {
    }

    void printAllPrimeFactors(int val) {
        cout << "Input: " << val << endl;

    }
};

int main() {
    PrimeFactor pf;

    pf.printAllPrimeFactors(100);
    pf.printAllPrimeFactors(123456789);
    pf.printAllPrimeFactors(32);
}

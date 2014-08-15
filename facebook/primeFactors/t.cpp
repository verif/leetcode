/* Find all prime factors of an given integer */

#include <iostream>
using namespace std;

class PrimeFactor {
public:
    bool isPrime(int v) {
        if (v < 2) return false;

        for (int i = 2; i*i <= v; i++) {
            if (v % i == 0) return false;
        }

        return true;
    }

    void printAllPrimeFactors(int val) {
        cout << "Input: " << val << endl;

        for (int i = 2; i <= val; i++) {
            while (isPrime(i) && val % i == 0) {
                cout << i << endl;
                val /= i;
            }
        }
    }
};

int main() {
    PrimeFactor pf;

    pf.printAllPrimeFactors(100);
    pf.printAllPrimeFactors(123456789);
}

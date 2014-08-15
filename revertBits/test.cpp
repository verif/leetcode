/* Reverse bits of an unsigned integer */
#include <iostream>

using namespace std;

unsigned int reverseBits(unsigned int v)
{
    unsigned int ret, i;

    ret = 0;
    while (i = v % 10) {
        v = (v - i) / 10;
        ret = ret * 10 + i;
    }

    return ret;
}

int main()
{
    while (1) {
        unsigned int val;
        cout << "Please give input unsigned integer: " << endl;
        cin >> val;
        cout << "Reversed results is: " << reverseBits(val) << endl;
    }
}

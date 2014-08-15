#include <iostream>

using namespace std;

int isPalindrome(int x)
{
    int val = 0;
    int org = x;

    if (x < 0) return 0;
    if (x < 10) return true;

    while (x) {
        val *= 10;
        val += (x % 10);
        x = x/10;
    }

    return (val == org);
}

int main(int argc, char** argv)
{
    int number;
    while (cin >> number) {
        int ret = isPalindrome(number);
        const char* str = ret ? " is" : " is not";
        cout << number << str << " palindrome" << endl;
    }
}

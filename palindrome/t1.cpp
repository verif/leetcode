/* Check if binary representation of a number is palindrome */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	int val = 0;
	int org = x;

	if (x < 0) return 0;
	if (x < 2) return true;

	while (x) {
	    val *= 2;
	    val += (x % 2);
	    x = x/2;
	}

	return (val == org);
    }
};

int main()
{
    int number;
    Solution* s = new Solution();
    while (cin >> number) {
        int ret = s->isPalindrome(number);
        const char* str = ret ? " is" : " is not";
        cout << number << str << " palindrome" << endl;
    }
}

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
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

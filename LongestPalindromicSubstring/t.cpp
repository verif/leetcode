#include <iostream>
#include <string>

using namespace std;

int getLongestPalindromicSubstringWithStartEnd(string str, int& start, int end)
{
    int ret = 0;
    while ((start >= 0) && (end < str.length())) {
        if (str.at(start) == str.at(end)) {
            ret += 2;
        }
        else {
            break;
        }
        start--;
        end++;
    }
    return ret;
}

// longest palindromic substring in 'str' and the middle of the substring is
// at position 'pivot'
int getLongestPalindromicSubstringAt(string str, int pivot, string& subStr)
{
    if (pivot < 0) return 0;
    if (pivot >= str.length()) return 0;

    subStr = str.substr(pivot, 1);
    int start = pivot - 1;
    int end = pivot + 1;
    int ret = 1;
    int len = 1;

    // First check odd length substring, where we have only one middle at
    // 'pivot'
    len += getLongestPalindromicSubstringWithStartEnd(str, start, end);
    ret = len;

    subStr = str.substr(start+1, len);

    // Second, check even length substring, where we have two middles - one is
    // 'pivot'.
    if ((pivot > 0) && (str.at(pivot) == str.at(pivot-1))) {
        len = 2;
        start = pivot - 2;
        end = pivot + 1;
        len += getLongestPalindromicSubstringWithStartEnd(str, start, end);
        if (subStr.length() < len) {
            ret = len;
            subStr = str.substr(start+1, len);
        }
    }

    if ((pivot < (str.length()-1)) && (str.at(pivot) == str.at(pivot+1))) {
        len = 2;
        start = pivot - 1;
        end = pivot + 2;
        len += getLongestPalindromicSubstringWithStartEnd(str, start, end);
        if (subStr.length() < len) {
            ret = len;
            subStr = str.substr(start+1, len);
        }
    }

    return ret;
}

int main()
{
    string inputStr;
    string subStr;
    int len;
    int maxLen = 0;
    string maxStr;
    while (1) {
        cin >> inputStr;
        maxLen = 0;
        for (int i = 0; i < inputStr.length(); i++) {
            len = getLongestPalindromicSubstringAt(inputStr, i, subStr);
            if (maxLen < len) {
                maxLen = len;
                maxStr = subStr;
            }
        }
        cout << "Longest substring of " << inputStr << " is: ";
        cout << "   " << maxStr << " length is " << maxLen << endl;
    }
    return 0;
}

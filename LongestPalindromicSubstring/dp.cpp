#include <string>
#include <iostream>
using namespace std;

#define MAX_LEN 1000
string getLongestPalindromicSubstr(string str)
{
    char fa[MAX_LEN][MAX_LEN];
    int i, j;
    int len = str.length();
    int maxLen;
    string subStr;

    if (len > MAX_LEN) {
        cout << "input string too long " << endl;
        exit(-1);
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            fa[i][j] = 0;
        }
    }

    for (i = 0; i < len; i++) {
            fa[i][i] = 1;
    }

    for (i = 0; i < len-1; i++) {
        fa[i][i+1] = (str.at(i) == str.at(i+1)) ? 1 : 0;
    }

    for (i = 2; i < len; i++) {
        for (j = 0; j < len - 2; j++) {
            if ((i+j) > (len-1)) break;
            if (fa[j+1][i+j-1]) {
                if (str.at(j) == str.at(i+j)) {
                    fa[j][i+j] = 1;
                }
            }
        }
    }

    maxLen = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (fa[i][j]) {
                if (maxLen < (j - i + 1)) {
                    maxLen = j - i + 1;
                    subStr = str.substr(i, j-i+1);
                }
            }
        }
    }

    return subStr;
}

int main()
{
    string inputStr;
    while (1) {
        cin >> inputStr;
        string maxStr = getLongestPalindromicSubstr(inputStr);
        cout << "Longest substring of " << inputStr << " is: ";
        cout << "   " << maxStr << endl;
    }
    return 0;
}

/* Longest Substring Without Repeating Characters */

#include <iostream>
#include <string>

using namespace std;

string longestSubstringWithoutRepeatingChar(string str)
{
    // ASCII has 256 chars
    char count[256];
    int* order = new int [str.length()];
    int* longestStrLen = new int [str.length()];
    int i;

    for (i = 0; i < 256; i++) {
        count[i] = 0;
    }
    for (i = 0; i < str.length(); i++) {
        order[i] = 0;
        longestStrLen[i] = 0;
    }

    // first iterate string once to populate 'order'/'count': O(n)
    const char* p = str.c_str();
    for (i = 0; i < str.length(); i++, p++) {
        count[*p] += 1;
        order[i] = count[*p];
    }

    for (i = 0; i < 256; i++) {
        count[i] = 1;
    }

    // scan the string again to find longest substring without repeating chars
    string subStr;
    int lastEnd = 0;
    int j;
    i = 0;
    while (i < str.length()) {
        for (j = lastEnd; j < str.length(); j++) {
            if (order[j] == count[str.at(j)]) {
                continue;
            }
            else {
                lastEnd = j;
                if (subStr.length() < (lastEnd - i)) {
                    subStr = str.substr(i, lastEnd - i);
                }
                count[str.at(j)] ++ ;
                while (str.at(i) != str.at(j)) {
                    count[str.at(i)] ++ ;
                    i++;
                }
                i++;
                break;
            }
        }
        if (j == str.length()) {
            if (j - i > subStr.length()) {
                subStr = str.substr(i, string::npos);
            }
            break;
        }
    }

    return subStr;
}

int main()
{
    string str;
    while (1) {
        cout << " Please give input string " << endl;
        cin >> str;
        string subStr = longestSubstringWithoutRepeatingChar(str); 
        cout << "Longest substring without repeating character is: " << subStr
            << endl;
    }
}

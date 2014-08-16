/*
   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
   of rows like this: (you may want to display this pattern in a fixed font for
   better legibility)
   P   A   H   N
   A P L S I I G
   Y   I   R

   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a
   number of rows:
   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1)
            return s;
        string rows[nRows];
        bool is_down = true;
        int row = 0;
        for (int i = 0; i < s.size(); i++) {
            rows[row].push_back(s[i]);
            if (is_down) {
                if (row == nRows - 1) {
                    is_down = false;
                    row--;
                }
                else {
                    row++;
               }
            }
            else {
                if (row == 0) {
                    is_down = true;
                    row++;
                }
                else {
                    row--;
               }
            }
        }

        string ret;
        for (int i = 0; i < nRows; i++)
           ret += rows[i];
        return ret;
    }
};

int main() {
    Solution s;
    string ret;
    string str = "PAYPALISHIRING";

    ret = s.convert(str, 3);
    cout << ret << endl;

    if (ret.compare("PAHNAPLSIIGYIR") == 0)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
    return 0;
}

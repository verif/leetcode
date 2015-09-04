/*
Input:
------
 
The input will contain a single, possibly empty, line containing a
space-separated list of strings to be sorted. Words will not contain spaces,
will contain only the lower-case letters a-z. Integers will be in the range
-999999 to 999999, inclusive. The line will be at most 1000 characters long.
 
Output:
-------
 
The program must output the list of strings, sorted per the requirements
above. Strings must be separated by a single space, with no leading space
at the beginning of the line or trailing space at the end of the line.
 
 
Constraints:
------------
 
The code you submit must take input from stdin and produce output to stdout
as specified above. No other output is permitted. You can assume the input
will be valid. Feel free to use standard libraries to assist in sorting.
 
In the examples below, the text "Input:" and "Output:" are not part of the
output, and neither are the blank lines.
 
 
Example 1:
----------
Input:
1
 
Output:
1
 
 
Example 2:
----------
Input:
 
car truck bus
 
Output:
 
bus car truck
 
 
Example 3:
----------
Input:
 
8 4 6 1 -2 9 5
 
Output:
 
-2 1 4 5 6 8 9
 
 
Example 4:
----------
Input:
 
car truck 8 4 bus 6 1
 
Output:
 
bus car 1 4 truck 6 8
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm> // for sort
using namespace std;

class SortInput {
public:
    void printSortedStringNumber(string & str) {
        vector<string> inputs;
        istringstream iss(str);
        vector<string> strings;
        vector<int> numbers;

        string tmp;
        while (iss >> tmp) {
            inputs.push_back(tmp);
            if (tmp[0] >= 'a' && tmp[0] <= 'z') {
                strings.push_back(tmp);
            }
            else numbers.push_back(atoi(tmp.c_str()));
        }
        std::sort(strings.begin(), strings.end());
        std::sort(numbers.begin(), numbers.end());

        int scnt = 0, ncnt = 0;
        for (int i = 0; i < inputs.size(); i++) {
            if (inputs[i][0] >= 'a' && inputs[i][0] <= 'z') {
                cout << strings[scnt++];
            }
            else {
                cout << numbers[ncnt++];
            }
            if (i != inputs.size()-1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    SortInput si;
    char line[1000];

    cin.getline(line, 1000);

    string str(line);
    si.printSortedStringNumber(str);
}

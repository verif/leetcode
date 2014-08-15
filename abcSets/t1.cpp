/*
input: aBc
output:
abc, abC, aBc, aBC
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
vector<string> getStringSets(string str) {
    vector<string> sets;
    string empty;
    sets.push_back(empty);

    for (unsigned int i = 0; i < str.length(); i++) {
        unsigned int size = sets.size();
        for (unsigned int j = 0; j < size; j++) {
            string ns = sets[j];
            sets[j].push_back(str[i]);
            ns.push_back(str[i] >= 'a' ? str[i] - ('a'-'A') : str[i] +
                         ('a'-'A'));
            sets.push_back(ns);
        }
    }

    return sets;
}
};

int main() {
    Solution s;
    vector<string> ret;

    ret = s.getStringSets("aBc");
    for (unsigned int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ";";
    }
    cout << endl;
}

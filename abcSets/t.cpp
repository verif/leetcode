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
    if (!str.length()) {
        sets.push_back(str);
        return sets;
    }
    vector<string> ret = getStringSets(str.substr(1));
    for (unsigned int i = 0; i < ret.size(); i++) {
        string s = ret[i];
        string ns = s;
        s.insert(s.begin(), str[0]);
        sets.push_back(s);
        ns.insert(ns.begin(), str[0] >= 'a' ? str[0] - ('a'-'A') : str[0] + ('a'-'A'));
        cout << str << ": " << s << " " << ns << endl;
        sets.push_back(ns);
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

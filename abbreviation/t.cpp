/*
Abbreviation: apple can be abbreviated to 5, a4, 4e, a3e, ...
    Given a target string (internationalization), and a set of strings, 
    return the minimal length of abbreviation of this target string so that it 
    won't conflict with abbrs of the strings in the set. 
    "apple" ["blade" -> a4 (5 is conflicted with "blade"
    "apple" ["plain" "amber" "blade"] -> ???
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // 'sort'
using namespace std;

class Abbrv {
    struct mycmp {
        bool operator () (string s1, string s2) {
            return s1.length() < s2.length();
        }
    };
public:
    bool isAbbrvMatch(string abbrvStr, string str) {
        unsigned int idx1 = 0, idx2 = 0;
        while (idx2 < str.length() && idx1 < abbrvStr.length()) {
            if (str[idx2] == abbrvStr[idx1]) {
                idx2++; idx1++;
                continue;
            }
            else {
                int cnt = 0;
                while (idx1 < abbrvStr.length() && (abbrvStr[idx1] >= '0' &&
                                                    abbrvStr[idx1] <= '9')) {
                    idx1++;
                    cnt++;
                }
                if (!cnt) return false;
                string sub = abbrvStr.substr(idx1-cnt, cnt);
                int num = atoi(sub.c_str());
                idx2 += num;
            }
        }
        return (idx2 == str.length() && idx1 == abbrvStr.length());
    }

    // use '0'/'1' to check if abbreviate the current char. 
    // For 'apple', '00000' => apple, '11111' => "5", '11011' => "2p2"
    void findAllAbbrvRecur(string &str, int pos, string &cur, vector<string>
                           &res) {
        if (pos == str.length()) {
            res.push_back(cur);
            return;
        }
        cur.push_back('0');
        findAllAbbrvRecur(str, pos+1, cur, res);
        cur.pop_back();
        cur.push_back('1');
        findAllAbbrvRecur(str, pos+1, cur, res);
        cur.pop_back();
    }
    void findAllAbbrv(string str, vector<string> &res) {
        string cur;
        // This will return all strings with '0'/'1'.
        findAllAbbrvRecur(str, 0, cur, res);

        // Now convert to correct abbreviation
        ostringstream oss;
        for (unsigned int i = 0; i < res.size(); i++) {
            oss.str("");
            string tmp = res[i];
            string newS;
            unsigned int j = 0;
            while (j < tmp.length()) {
                if (tmp[j] == '0') {
                    oss << str[j];
                    j++;
                }
                else {
                    int cnt = 0;
                    while (j < tmp.length() && tmp[j] == '1') {
                        j++;
                        cnt++;
                    }
                    oss << cnt;
                }
            }
            newS = oss.str();
            res[i] = newS;
        }
    }

    string shortestAbbrv(string str, vector<string>& sets) {
        string ret = str;
        vector<string> res;

        findAllAbbrv(str, res);

        std::sort(res.begin(), res.end(), mycmp());
        for (unsigned int i = 0; i < res.size(); i++) {
            bool matchFound = false;
            for (unsigned int j = 0; j < sets.size(); j++) {
                if (isAbbrvMatch(res[i], sets[j])) {
                    matchFound = true;
                    break;
                }
            }
            if (!matchFound) return res[i];
        }

        return str;
    }
};

int main() {
    Abbrv abv;

    vector<string> sets = {"plain", "amber", "blade"};
    string str = "apple";
    string ret;

    ret = abv.shortestAbbrv(str, sets);
    std::cout << ret << std::endl;
}

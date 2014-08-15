/*
   Write a function that calculates input strings with operators +,-,*,/ eg.
   5+5*6 should output 35
*/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

class ComputeString {
public:
    string getNextNumber(string& str, int &i) {
        string res;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            res.push_back(str[i++]);
        }

        return res;
    }

    int computeInputString(string str) {
        stack<string> stk;
        int res = 0, i = 0;
        while (i < str.length()) {
            if (str[i] == '*' || str[i] == '/') {
                char c = str[i];
                string l = stk.top();
                stk.pop();
                i++;
                string r = getNextNumber(str, i);
                int lv = atoi(l.c_str()), rv = atoi(r.c_str());
                int val = c == '*' ? lv*rv : lv/rv ;
                ostringstream oss;
                oss << val;
                stk.push(oss.str());
            }
            else {
                if (str[i] == '+' || str[i] == '-') {
                    stk.push(str.substr(i, 1));
                    i++;
                }
                else {
                    stk.push(getNextNumber(str, i));
                }
            }
        }

        while (!stk.empty()) {
            int rv = atoi(stk.top().c_str());
            stk.pop();
            if (stk.empty()) return rv;
            string op = stk.top(); stk.pop();
            int lv = atoi(stk.top().c_str());
            stk.pop();
            int tmp = op[0] == '+' ? lv+rv : lv-rv;
            ostringstream oss;
            oss << tmp;
            stk.push(oss.str());
            res = tmp;
        }

        return res;
    }
};

int main() {
    ComputeString cs;
    cout << "5+5*6 is: " << cs.computeInputString("5+5*6") << endl;
    cout << "5+5*6*7+8/2 is: " << cs.computeInputString("5+5*6*7+8/2") << endl;
    cout << "5+35*6*79+8/2 is: " << cs.computeInputString("5+35*6*79+8/2") << endl;
    cout << "5+5+8-2 is: " << cs.computeInputString("5+5+8-2") << endl;
}

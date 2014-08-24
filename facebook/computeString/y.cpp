/*
   Write a function that calculates input strings with operators +,-,*,/ eg.
   5+5*6 should output 35
*/

#include <stdlib.h>
#include <assert.h>
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
        int res;
        stack<string> stk;
        // - scan through the input string and do the * and / calculations first
        //   results will be pushed to stack
        // - then pop the stack and finish the + and - calculation
        int i = 0;
        while (i < str.length()) {
            if (str[i] == '*' || str[i] == '/') {
                // assume the left operand is in the stack
                // and right operand is following operator
                char c = str[i];
                i++;
                int rv = atoi(getNextNumber(str, i).c_str());
                int lv = atoi(stk.top().c_str()); stk.pop();
                int val = (c == '*') ? (lv * rv) : (lv / rv);
                ostringstream oss;
                oss << val;
                stk.push(oss.str());
            }
            else if (str[i] == '+' || str[i] == '-') {
                stk.push(str.substr(i, 1));
                i++;
            }
            else {
                stk.push(getNextNumber(str, i));
            }
        }
        // do the + and - calculations
        res = 0;
        while (stk.size() >= 3) {
            int rv  = atoi(stk.top().c_str()); stk.pop();
            char op = stk.top()[0]; stk.pop();
            int lv  = atoi(stk.top().c_str()); stk.pop();
            int val = (op == '+') ? lv + rv : lv - rv;
            ostringstream oss;
            oss << val;
            stk.push(oss.str());
        }
        if (!stk.empty()) {
          res = atoi(stk.top().c_str());
        }
        return res;
    }
};

int main() {
    ComputeString cs;
    cout << "1+2+3 is: " << cs.computeInputString("1+2+3") << endl;
    cout << "5+5*6 is: " << cs.computeInputString("5+5*6") << endl;
    cout << "5+5*6*7+8/2 is: " << cs.computeInputString("5+5*6*7+8/2") << endl;
    cout << "5+35*6*79+8/2 is: " << cs.computeInputString("5+35*6*79+8/2") << endl;
    cout << "5+5+8-2 is: " << cs.computeInputString("5+5+8-2") << endl;

    assert ((5+5*6)           == cs.computeInputString("5+5*6"));
    assert ((5+5*6*7+8/2)      == cs.computeInputString("5+5*6*7+8/2"));
    assert ((5+35*6*79+8/2)    == cs.computeInputString("5+35*6*79+8/2"));
    assert ((5+5+8-2)          == cs.computeInputString("5+5+8-2"));
    return 0;
}

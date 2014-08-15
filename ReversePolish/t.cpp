/*
   Evaluate the value of an arithmetic expression in Reverse Polish Notation.
   Valid operators are +, -, *, /. Each operand may be an integer or another
   expression.

   Some examples:
     ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    static bool isOperator(string op)
    {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    static int computeResult(string left, string right, string op)
    {
        int v1 = atoi(left.c_str());
        int v2 = atoi(right.c_str());
        switch (op.c_str()[0]) {
            case '+':
                return v1+v2;
            case '-':
                return v1-v2;
            case '*':
                return v1*v2;
            case '/': 
                return v1/v2;
            default:
                assert(0);
                break;
        }

        return -1;
    }

     int evalRPN(vector<string> &tokens) {
         string left, right, op1;
         vector<string>::iterator i1, i2, i3;

         if (tokens.size() == 1) {
             return atoi(tokens.at(0).c_str());
         }

         i1 = tokens.begin();
         assert(i1 != tokens.end());
         i2 = i1+1;
         assert(i2 != tokens.end());
         i3 = i2+1;
         assert(i3 != tokens.end());

         while (!isOperator(*i3)) {
             i1++;
             assert(i1 != tokens.end());
             i2++;
             assert(i2 != tokens.end());
             i3++;
         }

         int result = computeResult(*i1, *i2, *i3);
         string str = to_string(result);

         *i3 = str;
         tokens.erase(i1, i3);

         return evalRPN(tokens);
     }
};

int main()
{
    Solution s;

    vector<string> tokens;

    tokens.push_back("18");
    int result = s.evalRPN(tokens);
    cout << "result is: " << result << endl;

    tokens.clear();
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("*");

    result = s.evalRPN(tokens);
    cout << "result is: " << result << endl;

    tokens.clear();
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    result = s.evalRPN(tokens);
    cout << "result is: " << result << endl;

}

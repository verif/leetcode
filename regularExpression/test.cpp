/* Implement regular expression matching with support for '.' and '*' */

#include <iostream>
#include <string>
using namespace std;

string matchRegularExpr(string inputStr, string regExpr, int& begin, int& end)
{
    int i;
    int len = regExpr.length();
    int tmp;
    
    if (!len) {
        return "";
    }
    
    if (regExpr.at(0) == '.') {
        begin = 0;
        end++;
        matchRegularExpr(inputStr.substr(1, string::npos), regExpr.substr(1,
                                                  string::npos), tmp, end);
    }
    else if (regExpr.at(0) == '*') {
        begin = 0;
        matchRegularExpr(inputStr, regExpr.substr(1, string::npos), tmp, end);
    }
    else {
        string subStr;
        i = 0;
        while (i < len) {
            if (regExpr.at(i) == '.' || regExpr.at(i) == '*') break;
            subStr.append(1, regExpr.at(i));
            i++;
        }
        begin = inputStr.find(subStr);
        if (begin == string::npos) {
            end = -1;
            return "";
        }
        else {
            end += (begin + subStr.length());
            matchRegularExpr(inputStr.substr(begin + subStr.length(),
                                             string::npos),
                             regExpr.substr(subStr.length(), string::npos),
                             tmp, end);
        }
    } 

    if (end == -1) {
        return "";
    } else {
        return inputStr.substr(begin,end);
    }
}

int main()
{
    string inputStr, regExpr;
    while (1) {
	int begin, end;
        begin = 0;
        end = 0;
	cout << "Please give input string:" << endl;
	cin >> inputStr;
	cout << "Please give regular expression:" << endl;
	cin >> regExpr;
	matchRegularExpr(inputStr, regExpr, begin, end);
	if (end == -1) {
	    cout << "cannot match any string" << endl;
	}
	else {
            int len = (end - begin);
	    cout << "Match string is: " << inputStr.substr(begin, len) << endl;
	}
    }
    return 0;
}

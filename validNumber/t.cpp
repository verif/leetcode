/*
   Validate if a given string is numeric.
   Some examples:
   "0" => true
   " 0.1 " => true
   "abc" => false
   "1 a" => false
   "2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
     bool isNumber(const char *s) {
         if (!s) return false;

         const char *p = s;
         // remove ' ' at the beginning
         while (*p && *p == ' ') p++;
         if (!*p) return false;

         if (*p == '-' || *p == '+') {
             if (!(*(p+1) == '.' || (*(p+1) >= 0 && *(p+1) <= '9'))) {
                 return false;
             }
             p++;
         }
         if (*p < '0' || *p > '9') {
             if (*p != '.') {
                 return false;
             }
             else if (!*(p+1) || *(p+1) < '0' || *(p+1) > '9') {
                 return false;
             }
         }

         bool eFound = false;
         bool dotFound = false;
         while (*p) {
             if (*p >= '0' && *p <= '9') {
                 // do nothing
             }
             else if (*p == 'e') {
                 if (eFound) return false;
                 if (*(p+1) && (*(p+1) == '+' || *(p+1) == '-')) p++;
                 if (!(*(p+1) && *(p+1) >= '0' && *(p+1) <= '9')) {
                     return false; 
                 }
                 eFound = true;
             }
             else if(*p == '.') {
                 if (dotFound || eFound) return false;
                 dotFound = true;
             }
             else if (*p == ' ') {
                 while (*p) {
                     if (*p != ' ') return false;
                     p++;
                 }
                 return true;
             }
             else {
                 return false;
             }
             p++;
         }

         return true;
     }
};

int main()
{
    Solution s;
    bool ret;

    ret = s.isNumber("0");
    cout << "0 is number " << ret << endl;
    ret = s.isNumber(" 0.1 ");
    cout << "0.1 is number " << ret << endl;
    ret = s.isNumber("abc");
    cout << "abc is number " << ret << endl;
    ret = s.isNumber("1 a");
    cout << "1 a is number " << ret << endl;
    ret = s.isNumber("2e10");
    cout << "2e10 is number " << ret << endl;
    ret = s.isNumber("0123");
    cout << "0123 is number " << ret << endl;
    ret = s.isNumber("0e");
    cout << "0e is number " << ret << endl;
    ret = s.isNumber("0.");
    cout << "0. is number " << ret << endl;
    ret = s.isNumber("10.12");
    cout << "10.12 is number " << ret << endl;
    ret = s.isNumber("");
    cout << "\"\" is number " << ret << endl;
    ret = s.isNumber(".1");
    cout << ".1 is number " << ret << endl;
    ret = s.isNumber("1.");
    cout << "1. is number " << ret << endl;
    ret = s.isNumber(".");
    cout << ". is number " << ret << endl;
    ret = s.isNumber("0e ");
    cout << "0e is number " << ret << endl;
    ret = s.isNumber("-1.");
    cout << "-1. is number " << ret << endl;
    ret = s.isNumber("+.8");
    cout << "+.8 is number " << ret << endl;
    ret = s.isNumber("-.8");
    cout << "-.8 is number " << ret << endl;
    ret = s.isNumber(" -.");
    cout << " -. is number " << ret << endl;
    ret = s.isNumber("46.e3");
    cout << "46.e3 is number " << ret << endl;
    ret = s.isNumber("46e.");
    cout << "46e. is number " << ret << endl;
    ret = s.isNumber("6e6.5");
    cout << "6e6.5 is number " << ret << endl;
    ret = s.isNumber(" 005047e+6");
    cout << "  005047e+6 is number " << ret << endl;
    ret = s.isNumber(" 005047e-6");
    cout << "  005047e-6 is number " << ret << endl;
    return 0;
}

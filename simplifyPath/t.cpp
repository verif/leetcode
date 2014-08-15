/*
   Given an absolute path for a file (Unix-style), simplify it.

   For example,
   path = "/home/", => "/home"
   path = "/a/./b/../../c/", => "/c"
*/

#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
public:
     string simplifyPath(string path) {
         if (path.length() < 2) return path;
         if (path[0] != '/') return path;
         vector<string> dirs;
         
         int i = 0;
         while (i < path.length() && i != string::npos) {
             //assert(path[i] == '/');
             if (i+1 == path.length()) break;
             int j = path.substr(i+1).find('/');
             if (!j) { // '//'
                 i++;
                 continue;
             }
             string dir = j == string::npos ? path.substr(i+1) : 
                 path.substr(i+1, j);
             i = j == string::npos ? string::npos : i+j+1;
             if (!dir.compare(".")) continue;
             else if (!dir.compare("..")) {
                 if (!dirs.empty()) dirs.pop_back();
             }
             else { // regular directory
                 dirs.push_back(dir);
             }
         }

         if (!dirs.size()) return "/";

         string ret;
         for (i = 0; i < dirs.size(); i++) {
             ret += "/";
             ret += dirs[i];
         }

         return ret;
     }
};

int main()
{
    Solution s;
    string ret;
    string path = "/home/";

    ret = s.simplifyPath(path);
    cout << ret << endl;

    path = "/a/./b/../../c/";
    ret = s.simplifyPath(path);
    cout << ret << endl;

    path = "/a/./b/../../c/";
    ret = s.simplifyPath(path);
    cout << ret << endl;

    path = "//cd/ef/..//ab//..//pq//";
    ret = s.simplifyPath(path);
    cout << ret << endl;

    path = "/.";
    ret = s.simplifyPath(path);
    cout << ret << endl;

    return 0;
}

/*
   Given two words word1 and word2, find the minimum number of steps required
   to convert word1 to word2. (each operation is counted as 1 step.)

   You have the following 3 operations permitted on a word:
   a) Insert a character
   b) Delete a character
   c) Replace a character
*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// classic dynamic programming problem
class Solution {
public:
     int minDistance(string word1, string word2) {
         int len1 = word1.length();
         int len2 = word2.length();

         if (!len1) return len2;
         if (!len2) return len1;

         int p[len1+1][len2+1];
         int i, j;

         // initial condition
         for (i = 0; i <= len1; i++) p[i][0] = i;
         for (j = 0; j <= len2; j++) p[0][j] = j;

         for (i = 1; i <= len1; i++) {
             for (j = 1; j <= len2; j++) {
                 if (word1[i-1] == word2[j-1]) {
                     p[i][j] = p[i-1][j-1];
                 }
                 else {
                     p[i][j] = min(min(p[i][j-1], p[i-1][j]), p[i-1][j-1]) + 1;
                 }
                 cout << word1.substr(0, i) << "," << word2.substr(0, j) << ",";
                 cout << p[i][j] << endl;
             }
         }

         return p[len1][len2];
     }
};

int main()
{
    Solution s;
    int ret;
    string word1 = "FirstHelloWorldsecond";
    string word2 = "firstHelloWorldSecond";

    ret = s.minDistance(word1, word2);
    cout << ret << endl;
}

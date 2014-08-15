#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
     int lengthOfLongestSubstring(string s) {
	// ASCII has 256 chars
	char count[256];
	int* order = new int [s.length()];
	int* longestStrLen = new int [s.length()];
	int i;

	for (i = 0; i < 256; i++) {
	    count[i] = 0;
	}
	for (i = 0; i < s.length(); i++) {
	    order[i] = 0;
	    longestStrLen[i] = 0;
	}

	// first iterate string once to populate 'order'/'count': O(n)
	const char* p = s.c_str();
	for (i = 0; i < s.length(); i++, p++) {
	    count[*p] += 1;
	    order[i] = count[*p];
	}

	for (i = 0; i < 256; i++) {
	    count[i] = 1;
	}

	// scan the string again to find longest substring without repeating chars
	string subStr;
	int lastEnd = 0;
	int j;
	i = 0;
	while (i < s.length()) {
	    for (j = lastEnd; j < s.length(); j++) {
		if (order[j] == count[s.at(j)]) {
		    continue;
		}
		else {
		    lastEnd = j;
		    if (subStr.length() < (lastEnd - i)) {
			subStr = s.substr(i, lastEnd - i);
		    }
		    count[s.at(j)] ++ ;
		    while (s.at(i) != s.at(j)) {
			count[s.at(i)] ++ ;
			i++;
		    }
		    i++;
		    break;
		}
	    }
	    if (j == s.length()) {
		if (j - i > subStr.length()) {
		    subStr = s.substr(i, string::npos);
		}
		break;
	    }
	}

	return subStr.length();
     }
};

int main()
{
    Solution* s = new Solution();
    int len = s->lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar");
    cout << "length is " << len << endl;
}

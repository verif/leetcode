/*
   There is two dimensional array where each sub array (row) is sorted, i.e.
   [[1 1000 2000]
   [20 10001 5000]
   [55 10002 222222]]
   Find a minimum range contain a number from each row. For above array it
   should be (1000-1002) range.
*/

#include <vector>
#include <iostream>
#include <algorithm> // sort
using namespace std;

class MinRange {
public:
    typedef struct entry {
        int val;
        int row;
        entry(int v, int r) : val(v), row(r) {}
    } entry;

    struct mycmp {
        bool operator () (const entry* e1, const entry* e2) {
            return e1->val < e2->val;
        }
    };

    vector<int> findMinRange(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m) return res;
        int n = matrix[0].size();
        if (!n) return res;
        vector<int> index(m, 0);
        vector<entry*> en;

        // We need double ended priority Q to extract min/max value
        // Since there is no available such STL container, we implement it
        // here by ourselves
        for (int i = 0; i < m; i++) {
            entry *e = new entry(matrix[i][0], i);
            en.push_back(e);
            res.push_back(e->val);
        }
        
        std::sort(en.begin(), en.end(), mycmp());
        int minR = en.back()->val - en[0]->val;

        while (1) {
            entry *e = en[0];
            en.erase(en.begin());
            index[e->row]++;
            if (index[e->row] == m) break;
            e = new entry(matrix[e->row][index[e->row]], e->row);
            en.insert(en.begin(), e);
            // can do better using double ended priority queue
            std::sort(en.begin(), en.end(), mycmp());
            if (minR > en.back()->val - en[0]->val) {
                minR = en.back()->val - en[0]->val;
                res.clear();
                for (int i = 0; i < en.size(); i++) res.push_back(en[i]->val);
            }
        }

        return res;
    }
};

int main() {
    MinRange mr;
    vector<vector<int>> matrix = {{1, 1000, 2000}, {20, 1001, 5000}, {55,
        1002, 222222}};
    vector<int> ret;

    ret = mr.findMinRange(matrix);

    for (int i = 0; i < ret.size(); i++) cout << ret[i] << ",";
    cout << endl;
    return 0;
}

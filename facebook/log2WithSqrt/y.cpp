/*
   Write a function that computes log2() using sqrt().
*/

#include <math.h> // for 'sqrt'
#include <iostream>
using namespace std;

class LOG2 {
public:
    double log2(double val) {
        int i;
        double logx, logy;
        double valx, valy;

        // find out the upper and lower bounds of target value 
        // that are power of 2
        i = 0;
        while ((1 << i) < val)
            i++;

        logy = i;
        logx = logy - 1;

        valx = (1 << (i-1));
        valy = (1 << i);

        while (fabs(valx-val) > 0.000001) {
            double valm = sqrt(valx * valy);
            double logm = (logx + logy) / 2;
            if (valx == val)
                return logx;
            if (valm < val) {
               valx = valm;
               logx = logm;
            }
            else {
               valy = valm;
               logy = logm;
            }
        }
        return logx;
    }
};

int main() {
    LOG2 l;

    cout << "reference: " << log2(16) << " Actual: " << l.log2(16) << endl;
    cout << "reference: " << log2(1024) << " Actual: " << l.log2(1024) << endl;
    cout << "reference: " << log2(65536) << " Actual: " << l.log2(65536) << endl;
    cout << "reference: " << log2(999) << " Actual: " << l.log2(999) << endl;
    cout << "reference: " << log2(99) << " Actual: " << l.log2(99) << endl;
}

/*
   Write a function that computes log2() using sqrt().
*/

#include <math.h> // for 'sqrt'
#include <iostream>
using namespace std;

class LOG2 {
public:
    double log2(double val) {
        int lx, hx;
        double lval, hval;
	// find out the upper and lower bounds of target value 
	// that are power of 2
        hx = 0;
        while ((1 << hx) < val)
            hx++;
        lx = hx - 1;
        lval = (1 << lx);
        hval = (1 << hx);

        while (fabs(lval, val) > 0.000001) {
            if (lval == val)
            return lx;
        }
	    
	}
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

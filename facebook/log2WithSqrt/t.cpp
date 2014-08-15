/*
   Write a function that computes log2() using sqrt().
*/

#include <math.h> // for 'sqrt'
#include <iostream>
using namespace std;

class LOG2 {
public:
    double log2(double val) {
        double threshold = 0.000001;

        double y = 1, x = 0;

        while (y < val) {
            y *= 2;
            x++;
        }

        if (y == val) return x;
        double ly = y/2, ry = y;
        double lx = x-1, rx = x;
        
        double mx = (lx+rx)/2, my = sqrt(ly*ry);
        while (1) {
            if (fabs(val-my) < threshold) return mx;
            else if (my < val) {
                ly = my;
                lx = mx;
            } 
            else {
                ry = my;
                rx = mx;
            }
            mx = (lx+rx)/2;
            my = sqrt(ly*ry);
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

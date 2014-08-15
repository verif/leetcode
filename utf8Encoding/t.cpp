/*
   UTF-8 is a specific scheme for mapping a sequence of 1-4 bytes to a number
   from 0x000000 to 0x10FFFF:

   00000000 -- 0000007F:    0xxxxxxx
   00000080 -- 000007FF:    110xxxxx 10xxxxxx
   00000800 -- 0000FFFF:    1110xxxx 10xxxxxx 10xxxxxx
   00010000 -- 001FFFFF:    11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

#include <iostream>
using namespace std;

class UTF8 {
public: 
    unsigned int encode(unsigned int in) {
        unsigned int res = 0;
        unsigned char b1 = 0, b2 = 0, b3 = 0, b4 = 0;
        if (in <= 0x7F) return in << 24;
        if (in >= 0x80 && in <= 0x7FF) {
            b1 = in>>6  & 0x1F | 0xC0;
            b2 = in & 0x3F | 0x80;
        }
        else if (in <= 0xFFFF) {
            b1 = in >> 12 & 0xF | 0xE0;
            b2 = in >> 6 & 0x3F | 0x80;
            b3 = in & 0x3F | 0x80;
        }
        else if (in <= 0x1FFFFF) {
            b1 = in >> 18 & 0x7 | 0xF0;
            b2 = in >> 12 & 0x3F | 0x80;
            b3 = in >> 6 & 0x3F | 0x80;
            b4 = in & 0x3F | 0x80;
        }

        res |= ((b1 << 24) | (b2 << 16) | (b3 << 8) | b4);

        return res;
    }
    unsigned int decode(unsigned int utfCode) {
        unsigned int res = 0;

        unsigned char b4 = utfCode & 0xFF;
        unsigned char b3 = utfCode >> 8 & 0xFF;
        unsigned char b2 = utfCode >> 16 & 0xFF;
        unsigned char b1 = utfCode >> 24 & 0xFF;

        if (b1 >= 0xF0) {
            res = ((b4 & 0x3F) | ((b3 & 0x3F) << 6) | ((b2 & 0x3F) << 12) | 
                   ((b1 & 0x7) << 18));
        }
        else if (b1 >= 0xE0) {
            res = ((b3 & 0x3F) | ((b2 & 0x3F) << 6) | ((b1 & 0xF) << 12));
        }
        else if (b1 >= 0xC0) {
            res = ((b2 & 0x3F) | ((b1 & 0x1F) << 6));
        }
        else {
            res = b1;
        }

        return res;
    }
}
;
int main()
{
    UTF8 u8;

    unsigned int v = 15;
    cout << v << " " << u8.encode(v) << " " << u8.decode(u8.encode(v)) << endl;
    v = 127;
    cout << v << " " << u8.encode(v) << " " << u8.decode(u8.encode(v)) << endl;
    v = 0x82;
    cout << v << " " << u8.encode(v) << " " << u8.decode(u8.encode(v)) << endl;
    v = 0x888;
    cout << v << " " << u8.encode(v) << " " << u8.decode(u8.encode(v)) << endl;
    v = 0x1FFFF;
    cout << v << " " << u8.encode(v) << " " << u8.decode(u8.encode(v)) << endl;
}

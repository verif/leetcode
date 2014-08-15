/*
   Given a 2D board containing 'X' and 'O', capture all regions surrounded by
   'X'.
   A region is captured by flipping all 'O's into 'X's in that surrounded
   region.
   For example,
   X X X X
   X O O X
   X X O X
   X O X X
   After running your function, the board should be:
   X X X X
   X X X X
   X X X X
   X O X X
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
     void solve(vector<vector<char>> &board) {
         int numRows = board.size();
         if (numRows <=1 ) return;
         int numColumns = board[0].size();

         // Find all 'O's on the border
         queue<pair<int,int>> oq;
         int i, j;

         for (j = 0;  j < numColumns; j++) { 
             if (board.at(0).at(j) == 'O') {
                 pair p(0,j);
                 board.at(0).at(j) = 'Y';
                 oq.push(p);
             }
             if (board.at(numRows-1).at(j) == 'O') {
                 pair p(numRows-1, j);
                 board.at(numRows-1).at(j) = 'Y';
                 oq.push(p);
             }
         }

         for (i = 0; i < numRows; i++) {
             if (board.at(i).at(0) == 'O') {
                 pair p(i, 0);
                 board.at(i).at(0) = 'Y';
                 oq.push(p);
             }
             if (board.at(i).at(numColumns-1) == 'O') {
                 pair p(i, numColumns-1);
                 board.at(i).at(numColumns-1) = 'Y';
                 oq.push(p);
             }
         }
         
         // Do BFS seach to find non-surrounded 'O's
         while (p = oq.front()) {
             oq.pop();
             int x = p->row;
             int y = p->col;
             Position* q = NULL;
             if (x > 0 && board.at(x-1).at(y) == 'O') {
                 q = new Position(x-1, y);
                 board.at(i-1).at(y) = 'Y';
                 oq.push(q);
             }
             if (x < numRows-1 && board.at(x+1).at(y) == 'O') {
                 q = new Position(x+1, y);
                 board.at(x+1).at(y) = 'Y';
                 oq.push(q);
             }
             if (y > 0 && board.at(x).at(y-1) == 'O') {
                 q = new Position(x, y-1);
                 board.at(x).at(y-1) = 'Y';
                 oq.push(q);
             }
             if (y < numColumns-1 && board.at(x).at(y+1) == 'O') {
                 q = new Position(x, y+1);
                 board.at(x).at(y+1) = 'Y';
                 oq.push(q);
             }
         }

         for (i = 0; i < numRows; i++) {
             for (j = 0; j < numColumns; j++) {
                 if (board.at(i).at(j) == 'O') {
                     board.at(i).at(j) = 'X';
                 }
                 else if (board.at(i).at(j) == 'Y') {
                     board.at(i).at(j) = 'O';
                 }
             }
         }
     }
};

static void printRegion(vector<vector<char>>& board)
{
    int i, j;
    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board.at(0).size(); j++) {
            cout << board.at(i).at(j);
        }
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<char>> board;
    vector<char> r1;
    vector<char> r2;
    vector<char> r3;
    vector<char> r4;

    r1.push_back('X');
    r1.push_back('X');
    // r1.push_back('X');
    r1.push_back('X');
    board.push_back(r1);

    r2.push_back('X');
    r2.push_back('O');
    // r2.push_back('O');
    r2.push_back('X');
    board.push_back(r2);

    r3.push_back('X');
    // r3.push_back('X');
    r3.push_back('X');
    r3.push_back('X');
    board.push_back(r3);

    r4.push_back('X');
    r4.push_back('O');
    r4.push_back('X');
    r4.push_back('X');
    // board.push_back(r4);

    cout <<"Old Region: " << endl;
    printRegion(board);
    s.solve(board);
    cout << "New region: " << endl;
    printRegion(board);
}

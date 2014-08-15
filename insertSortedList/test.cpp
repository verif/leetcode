/* Insert into a Cyclic Sorted List */

#include <iostream>
using namespace std;

typedef struct Node {
    Node* next;
    int val;
} Node;

void printList(Node* head)
{
    if (!head) return;
    cout << "List Item: " << head->val << endl;

    Node* next = head->next;
    while (next != head) {
        cout << "List Item: " << next->val << endl;
        next = next->next;
    }
}

void insert(Node * aNode, int x)
{
    Node* n = new Node(); 
    n->val = x;
    if (!aNode) {
        n->next = n;
        return;
    }
    Node* prev = aNode;
    Node* next = aNode->next;
    Node* head = aNode;
    Node* tail = aNode;
    do {
        if (prev->val <= x && next->val >= x) {
            prev->next = n;
            n->next =  next;
            return;
        }
        if (next->val < head->val) {
            head = next;
            tail = prev;
        }
        if (next == head) tail = prev;
        prev = prev->next;
        next = next->next;
     } while (prev != aNode);

    // Not found a place to insert after a full list search, could be due to:
    // 1. only one node in the list
    // 2. 'x' is larger the largest value in the list or smaller than the
    // smallest value in the list. 
    // In either case, insert beween head & tail
    n->next = tail->next;
    tail->next = n;

    return;
}

int main()
{
    Node n1, n2, n3;
    n1.val = 4;
    /*
    n1.next = &n2;
    n2.val = 4;
    n2.next = & n3;
    n3.val = 4;
    n3.next = & n1;
    */
    n1.next = & n1;

    insert(&n1, 3);

    printList(&n1);
    return 0;
}

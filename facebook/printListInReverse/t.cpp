/*
   Print a list in reverse
*/

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
} ListNode;

class ReversePrint {
public:
    void reversePrint(ListNode *head) {
	if (!head) return;

	reversePrint(head->next);
	cout << head->val << endl;
    }
};

int main()
{
    ReversePrint s;

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    (void) s.reversePrint(&n1);

}

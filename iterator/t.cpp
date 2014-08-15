/*
   Program an iterator for a List which may include nodes or List  i.e.  * {0,
   {1,2}, 3 ,{4,{5, 6}}} Iterator returns 0 - 1 - 2 - 3 - 4 - 5 - 6
*/

#include <assert.h>
#include <iostream>
#include <stack>
using namespace std;

class ListNode {
friend class ListNodeI;
public:
    ListNode() : val(-1), next(NULL) {}
    ListNode(int v) : val(v), next(NULL) {}
    int getValue() { return val;}
    ListNode* getNext() {return next;}
    virtual ListNode* getHead() {return NULL;}
    virtual bool isComposite() { return false;}
    void setNext(ListNode *nxt) { next = nxt;}
    virtual void insertNode(ListNode* cn) {}
private:
    int val;
    ListNode* next;
};

class CompositeListNode : public ListNode {
friend class CompositeListNodeI;
public:
    CompositeListNode() : head_(NULL), tail_(NULL) {}
    virtual ListNode* getHead() { return head_;}
    virtual bool isComposite() { return true;}
    void insertNode(ListNode* cn);
private:
    ListNode *head_;
    ListNode *tail_;
};

void CompositeListNode::insertNode(ListNode* cn) {
    if (!head_) { head_ = tail_ = cn;}
    else {
        tail_->setNext(cn);
        tail_ = cn;
    }
}

class ListNodeI {
public:
    ListNodeI() : cur_(NULL) {}
    ListNodeI(ListNode* ln) : cur_(ln) {}
    virtual bool hasNext() { return cur_ != NULL;}
    virtual bool isComposite() { return false;}
    ListNode* getCur() { return cur_;}
    void nextCur() {cur_ = cur_->getNext();}
    virtual ListNode* next() {
        ListNode* ret = cur_; 
        cur_ = cur_->getNext(); 
        return ret;
    }
    virtual void pushIterator(ListNodeI* li) {}
protected:
    ListNode* cur_;
};

class CompositeListNodeI : public ListNodeI {
public:
    CompositeListNodeI(ListNode* ln);
    virtual bool hasNext();
    virtual ListNode* next();
    virtual bool isComposite() { return true;}
    virtual void pushIterator(ListNodeI* li) {stk_.push(li);} 
private:
    stack<ListNodeI*> stk_;
};

ListNodeI* createIterator(ListNode* ln) {
    if (ln->isComposite()) {
        ListNodeI* nli = ln->getHead()->isComposite() ? new CompositeListNodeI(ln->getHead()) :
            new ListNodeI(ln->getHead());
        return nli;
    }
    else {
        return new ListNodeI(ln);
    }
}

CompositeListNodeI::CompositeListNodeI(ListNode* ln) {
    assert(ln->isComposite());
    cur_ = ln;
    ListNodeI *li = createIterator(ln);
    stk_.push(li);
}

bool CompositeListNodeI::hasNext() {
    if (stk_.empty()) return false;
    ListNodeI* li = stk_.top();
    return li->hasNext();
}

ListNode* CompositeListNodeI::next() {
    if (stk_.empty()) return NULL;
    ListNodeI* li = stk_.top();
    ListNode* ret = li->next();
    if (li->getCur() && !li->isComposite() && li->getCur()->isComposite()) {
        ListNodeI* nli = createIterator(li->getCur());
        stk_.push(nli);
    }
    while (!hasNext()) {
        stk_.pop();
        if (stk_.empty()) return ret;
        ListNodeI* li2 = stk_.top();
        li2->nextCur();
        if (!li2->getCur()) { // end of list
            while (!stk_.top()->getCur()) {
                stk_.pop();
                if (stk_.empty()) return ret;
                stk_.top()->nextCur();
            }
        }
        else if (li2->getCur()->isComposite()) {
            ListNodeI* nli = createIterator(li2->getCur());
            stk_.push(nli);
        }
    }
    return ret;
}

int main() {
    CompositeListNode n;

    // {0, {1,2}, 3, {4, {5, 6}}}
    ListNode n0(0);
    ListNode n11(1), n12(2);
    CompositeListNode n1;
    n1.insertNode(&n11);
    n1.insertNode(&n12);

    ListNode n2(3);
    CompositeListNode n3;
    ListNode n31(4);
    n3.insertNode(&n31);
    CompositeListNode n32;
    ListNode n321(5), n322(6); 
    n32.insertNode(&n321);
    n32.insertNode(&n322);
    n3.insertNode(&n32);
    
    n.insertNode(&n0);
    n.insertNode(&n1);
    n.insertNode(&n2);
    n.insertNode(&n3);

    CompositeListNodeI it(&n);
    while (it.hasNext()) {
        ListNode* ln = it.next();
        cout << ln->getValue() << endl;
    }
}

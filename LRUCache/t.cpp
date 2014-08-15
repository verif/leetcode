/*
   Design and implement a data structure for Least Recently Used (LRU) cache.
   It should support the following operations: get and set.



   get(key) - Get the value (will always be positive) of the key if the key
   exists in the cache, otherwise return -1.

   set(key, value) - Set or insert the value if the key is not already present.
   When the cache reached its capacity, it should invalidate the least recently
   used item before inserting a new item.
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <assert.h>

using namespace std;

class LRUCache{

    typedef struct ListNode {
        int key;
        ListNode* prev;
        ListNode* next;
        ListNode(int x) : key(x), prev(NULL), next(NULL) {}
    } ListNode;

    typedef struct CacheItem {
        int val;
        ListNode* keyAddr;
        CacheItem(int x, ListNode* addr) : val(x), keyAddr(addr) {}
    } CacheItem;

public:
    void print() {
        ListNode* p = head;
        while (p) {
            int key = p->key;
            cout << "Key: " << key;
            unordered_map<int, CacheItem*>::const_iterator it2 = cache.find(key);
            cout << "   Value: " << it2->second->val << endl;
            p = p->next;
        }
    }
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        head = NULL;
        tail = NULL;
    }
         
    bool removeLeastUsedItem() {
        if (!tail) {
            assert(!head);
            return false;
        }

        cache.erase(tail->key);

        if (head == tail) {
            assert(!tail->prev);
            assert(!head->next);
            delete head;
            tail = NULL;
            head = NULL;
            return true;
        }
        
        // remove tail
        tail->prev->next = NULL;
        tail = tail->prev;

        return true;
    }

    int get(int key) {
        unordered_map<int, CacheItem*>::const_iterator it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        else {
            // promote to head
            ListNode* p = it->second->keyAddr;
            if (p != head) {
                if (p == tail) tail = p->prev;
                p->prev->next = p->next;
                if (p->next) p->next->prev = p->prev;
                p->prev = NULL;
                p->next = head;
                head->prev = p;
                head = p;
            }
            return it->second->val;
        }
    }
             
    void set(int key, int value) {
        unordered_map<int, CacheItem*>::iterator it = cache.find(key);
        if (it != cache.end()) {
            it->second->val = value;
            // promote to head
            ListNode* p = it->second->keyAddr;
            if (p != head) {
                if (p == tail) tail = p->prev;
                p->prev->next = p->next;
                if (p->next) p->next->prev = p->prev;
                p->prev = NULL;
                p->next = head;
                head->prev = p;
                head = p;
            }
        }
        else {
            if (cache.size() == maxSize) {
                if (!removeLeastUsedItem()) return;
            }
            ListNode* n = new ListNode(key);
            CacheItem* item = new CacheItem(value, n);
            if (!head) {
                head = tail = n;
            }
            else {
                // insert at head
                head->prev = n;
                n->next = head;
                head = n;
            }
            pair<int, CacheItem*> p(key, item);
            cache.insert(p);
        }
    }
private:
    int maxSize;
    unordered_map<int, CacheItem*> cache;
    ListNode* head;
    ListNode* tail;
};

int main()
{
    LRUCache lru(3);

    lru.set(2, 1);
    lru.set(1, 1);
    cout << lru.get(2) << endl;
    lru.set(4, 1);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    lru.set(5, 1);
    lru.set(2, 2);
    cout << lru.get(4) << endl;
    cout << lru.get(5) << endl;
    cout << lru.get(1) << endl;

    lru.print();
}


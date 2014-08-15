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

using namespace std;

class LRUCache{
    typedef struct DListNode {
        int key;
        int value;
        DListNode *prev;
        DListNode *next;
        DListNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    } DListNode;
    
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        _head = _tail = NULL;
    }
    
    void moveKeyToListHead(DListNode *p) {
        if (p == _head) return;
        if (p == _tail) {
            _tail = p->prev;
        }
        //first detach 'p' from current position
        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        // move 'p' to head
        p->prev = NULL;
        p->next = _head;
        _head->prev = p;
        _head = p;
    }
    
    void removeLeastUsedItem() {
        if (!_tail) return;
        if (_head == _tail) {
            _head = _tail = NULL;
            return;
        }
        // Now remove from the hashtable
        _keyMap.erase(_tail->key);
        
        DListNode *tmp = _tail;
        _tail = _tail->prev;
        _tail->next = NULL;
        
        delete tmp;
    }
    
    int get(int key) {
        int ret = -1;
        if (_keyMap.find(key) != _keyMap.end()) {
            ret = _keyMap[key]->value;
            moveKeyToListHead(_keyMap[key]);
        }

        return ret;
    }
    
    void set(int key, int value) {
        if (_keyMap.find(key) != _keyMap.end()) {
            _keyMap[key]->value = value;
            moveKeyToListHead(_keyMap[key]);
        }
        else {
            DListNode *newNode = new DListNode(key, value);
            newNode->next = _head;
            if (_head) _head->prev = newNode;
            else {
                _head = _tail = newNode;
            }
            _head = newNode;
            
            _keyMap[key] = newNode;
            
            if (_size == _capacity) {
                removeLeastUsedItem();
            }
            else _size++;
        }
    }
private:
    int _capacity;
    int _size;
    DListNode *_head, *_tail; // head/tail of the doubly linked list for 'key'
    unordered_map<int, DListNode*> _keyMap;
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

    // lru.print();
}


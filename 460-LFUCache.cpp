#include <unordered_map>
#include <algorithm>
using namespace std;
struct Node
{
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList
{
private:
    Node *head, *tail;
    int size;

public:
    DoubleLinkedList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        tail->prev = head;
        head->next = tail;
    }

    void addLast(Node *x)
    {
        x->next = tail;
        x->prev = tail->prev;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    Node *removeFirst()
    {
        if (head->next == tail)
        {
            return nullptr;
        }
        Node *first = head->next;
        remove(first);
        return first;
    }
};

class LFUCache
{
private:
    int minFreq, capacity;
    unordered_map<int, Node *> key_table;
    unordered_map<int, DoubleLinkedList> freq_table;
    void increaseFreq(int key)
    {
        Node *x = key_table[key];
        freq_table[x->freq].remove(x);
        x->freq++;
        freq_table[x->freq].addLast(x);
        minFreq = min(x->freq, minFreq);
    }

    void updateTable(int key, int value)
    {
        key_table[key]->val = value;
        increaseFreq(key);
    }

    void removeLeastFreq()
    {
        Node *x = freq_table[minFreq].removeFirst();
        key_table.erase(x->key);
    }

    void addNewNode(int key, int value)
    {
        Node *x = new Node(key, value);
        key_table[key] = x;
        freq_table[x->freq].addLast(x);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0)
    {
        key_table.clear();
        freq_table.clear();
    }

    int get(int key)
    {
        if (capacity == 0)
        {
            return -1;
        }

        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            return -1;
        }
        increaseFreq(key);
        return key_table[key]->val;
    }

    void put(int key, int value)
    {
        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            if (capacity == key_table.size())
            {
                removeLeastFreq();
            }
            addNewNode(key, value);
            minFreq = 1;
        }
        else
        {
            updateTable(key, value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
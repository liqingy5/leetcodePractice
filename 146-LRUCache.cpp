#include <unordered_map>

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
    int size = 0;

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
        x->prev = tail->prev;
        x->next = tail;
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
    int _size()
    {
        int left = size;
        return left;
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
        if (freq_table[x->freq]._size() == 0)
        {
            freq_table.erase(x->freq);
            if (minFreq == x->freq)
                minFreq++;
        }
        x->freq++;
        addNewNode(x);
    }

    void updateTable(int key, int value)
    {
        key_table[key]->val = value;
        increaseFreq(key);
    }

    void removeLeastFreq()
    {
        Node *x = freq_table[minFreq].removeFirst();
        if (x)
        {
            key_table.erase(x->key);
        }
        if (freq_table[minFreq]._size() == 0)
        {
            freq_table.erase(minFreq);
            if (minFreq == x->freq)
                minFreq++;
        }
    }

    void addNewNode(Node *x)
    {
        auto it = freq_table.find(x->freq);
        if (it == freq_table.end())
        {
            freq_table[x->freq] = DoubleLinkedList();
        }
        freq_table[x->freq].addLast(x);
        key_table[x->key] = x;
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
        if (capacity == 0)
        {
            return;
        }
        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            if (capacity == key_table.size())
            {
                removeLeastFreq();
            }
            minFreq = 1;
            Node *x = new Node(key, value);
            addNewNode(x);
        }
        else
        {
            updateTable(key, value);
        }
    }
};
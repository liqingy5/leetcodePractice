#include <unordered_map>

using namespace std;
struct Node
{
    int key, value;
    Node *prev = nullptr, *next = nullptr;
    Node(int key, int value) : key(key), value(value) {}
};

class DoubleLinkedList
{
private:
    Node *head, *tail;

public:
    int size;
    DoubleLinkedList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
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
};
class LRUCache
{
private:
    unordered_map<int, Node *> map;

private:
    DoubleLinkedList cache;
    int cap;

public:
    LRUCache(int cap) : cap(cap)
    {
        map = unordered_map<int, Node *>();
        cache = DoubleLinkedList();
    }

    int get(int key)
    {
        if (!map[key])
        {
            return -1;
        }
        makeRecently(key);
        return map[key]->value;
    }

    void put(int key, int val)
    {
        if (map[key])
        {
            deleteKey(key);
            addRecently(key, val);
        }
        else
        {
            if (cache.size == cap)
            {
                removeLeastRecently();
            }
            addRecently(key, val);
        }
    }

private:
    void makeRecently(int key)
    {
        Node *x = map[key];
        cache.remove(x);
        cache.addLast(x);
    }

    void addRecently(int key, int val)
    {
        Node *node = new Node(key, val);
        map[key] = node;

        cache.addLast(node);
    }

    void deleteKey(int key)
    {
        Node *node = map[key];
        cache.remove(node);
        map.erase(key);
    }

    void removeLeastRecently()
    {
        Node *removedNode = cache.removeFirst();
        map.erase(removedNode->key);
    }
};


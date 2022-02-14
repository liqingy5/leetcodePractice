struct Node
{   int key, value;
    Node *prev = nullptr, *next = nullptr;
    Node(int key, int value) : key(key), value(value){}
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
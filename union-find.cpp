#include <iostream>
using namespace std;
class UF
{
private:
    int n = 0;
    int *parent;

public:
    UF(int n) : n(n), parent(new int[n])
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    bool Connect(int p, int q)
    {
        int nodeP = Find(p);
        int nodeQ = Find(q);
        return nodeP == nodeQ;
    }

    int Find(int node)
    {
        while (parent[node] != node)
        {
            node = parent[node];
        }
        return node;
    }

    void Union(int p, int q)
    {
        int nodeP = Find(p);
        int nodeQ = Find(q);
        if (nodeP == nodeQ)
            return;
        parent[nodeP] = nodeQ;
        return;
    }

    int count()
    {
        return n;
    }
};
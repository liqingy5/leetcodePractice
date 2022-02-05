#include <iostream>
using namespace std;
class UF
{
private:
    int n = 0;
    int *parent; // record the parent node of current node;

    int *size; // add size array track how many nodes are attached to this parent;

public:
    UF(int n) : n(n), parent(new int[n]), size(new int[n])
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
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
            parent[node] = parent[parent[node]]; /// to decrease the size of the tree need to search
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
        if (size[nodeP] > size[nodeQ]) // check who has less nodes
        {
            parent[nodeQ] = nodeP;
            size[nodeP] += size[nodeQ]; // update the size of nodes to the parentNode
        }
        else
        {
            parent[nodeP] = nodeQ;
            size[nodeQ] += size[nodeP];
        }
        return;
    }

    int count()
    {
        return n;
    }
};
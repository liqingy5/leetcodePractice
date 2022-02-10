#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> table = {{2, 3, 5},
                                 {0, 1, 0},
                                 {1, 1, 2}};
    auto compare = [](vector<int> p, vector<int> q)
    { return p[2] < q[2]; };
    sort(table.begin(), table.end(), compare);

    for (auto p : table)
    {
        for (auto e : p)
        {
            cout << e;
        }
        cout << endl;
    }
}
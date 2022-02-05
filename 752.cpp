#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find(target) != dead.end())
            return -1;
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        int depth = 0;
        while (q.size() > 0)
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                string curr = q.front();
                q.pop();
                if (dead.find(curr) != dead.end())
                    continue;
                if (curr == target)
                {
                    return depth;
                }
                for (int j = 0; j < 4; ++j)
                {
                    string temp = curr;
                    temp[j] = ((curr[j] - '0') + 1) % 10 + '0';
                    if (visited.find(temp) == visited.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                    temp[j] = ((curr[j] - '0') - 1 + 10) % 10 + '0';

                    if (visited.find(temp) == visited.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            ++depth;
        }
        return -1;
    }
};

int main()
{
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    Solution solution;
    solution.openLock(deadends, target);
}
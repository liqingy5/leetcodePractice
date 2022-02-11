#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // make adjacency list, index is "from", pair.fist is dist,pair.second is "to"
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        for (auto t : times)
        {
            int from = t[0];
            int to = t[1];
            int dist = t[2];
            graph[from].push_back({dist, to});
        }
        // call dijkstra function
        vector<int> distTable = dijkstra(graph, k);

        int res = 0;

        for (int i = 1; i <= n; ++i)
        {
            // if a node not connected
            if (distTable[i] == INT_MAX / 2)
            {
                return -1;
            }
            // return the max minimum route for all nodes.
            res = max(distTable[i], res);
        }
        return res;
    }

    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start)
    {
        // make dp table to store the minimum distance from start to each node
        vector<int> dp(graph.size(), INT_MAX / 2);
        // base case
        dp[start] = 0;
        // add adjacents to priority queue to pop smallest distance adjacent each time.
        priority_queue<pair<int, int>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            pair<int, int> currentState = pq.top();
            pq.pop();

            int currId = currentState.second;
            int currDist = -currentState.first;
            // if vistied and have smaller distance
            if (dp[currId] < currDist)
            {
                continue;
            }
            // iterator neighbors, update dp table and push to pq.
            for (auto n : graph[currId])
            {
                int nextId = n.second;
                int nextDistance = n.first;
                int distToNext = dp[currId] + nextDistance;
                if (distToNext < dp[nextId])
                {
                    dp[nextId] = distToNext;

                    pq.push({-distToNext, nextId});
                }
            }
        }
        return dp;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int start = 2;
    Solution solution;
    cout << solution.networkDelayTime(times, n, start) << endl;
}
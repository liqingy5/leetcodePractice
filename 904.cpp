#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0, right = 0, result = 0, sublength = 0;
        unordered_map<int, int> map;
        for (right = 0; right < fruits.size(); right++)
        {
            map[fruits[right]]++;

            if (map.size() > 2)
            {
                map[fruits[left]]--;
                if (map[fruits[left]] == 0)
                    map.erase(fruits[left]);
                left++;
            }

            sublength = right - left + 1;
            result = result < sublength ? sublength : result;
        }
        return result;

        // unordered_map<int, int> count;
        // int i, j;
        // for (i = 0, j = 0; j < tree.size(); ++j)
        // {
        //     count[tree[j]]++;
        //     if (count.size() > 2)
        //     {
        //         if (--count[tree[i]] == 0)
        //             count.erase(tree[i]);
        //         i++;
        //     }
        // }
        // return j - i;
    }
};
int main()
{
    unordered_map<int, int> map;
    Solution solution;
    vector<int> fruits = {1, 2, 1};
    cout << solution.totalFruit(fruits);
}
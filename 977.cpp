#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1, k = nums.size() - 1;
        while (left <= right && k >= 0)
        {
            if (nums[right] * nums[right] < nums[left] * nums[left])
            {
                result[k] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[k] = nums[right] * nums[right];
                right--;
            }
            k--;
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution solution;
    solution.sortedSquares(nums);
    // for (auto c : nums)
    // {
    //     cout << c;
    // }
    // cout << endl;
}

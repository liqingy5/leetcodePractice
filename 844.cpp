#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<char> backspaceCompare(string s, string t)
    {
        vector<char> stack1;
        vector<char> stack2;
        compare(stack1, s);
        compare(stack2, t);
        return stack2;
    }
    void compare(vector<char> &stack, string s)
    {
        for (auto c : s)
        {
            if (c == '#')
            {
                if (stack.size() > 0)
                {
                    stack.pop_back();
                }
            }
            else
                stack.push_back(c);
        }
    }
};
int main()
{
    string s = "ab#c";
    string t = "ab#c";
    Solution solution;
    vector<char> stack = solution.backspaceCompare(s, t);
    for (auto c : stack)
    {
        cout << c;
    }
    cout << endl;
}
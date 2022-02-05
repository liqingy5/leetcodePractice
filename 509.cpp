#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    // solution 1
    // int fib(int n) {
    //     int table[] ={0,1};
    //     if (n<=1){
    //         return table[n];
    //     }
    //     for(int i=2;i<=n;i++){
    //         swap(table[1],table[0]);
    //         table[1] = table[0]+table[1];
    //     }
    //     return table[1];
    // }

    // solution 2
    // int fib(int n){
    //     if (n==0){
    //         return 0;
    //     }
    //     if(n==1){
    //         return 1;
    //     }
    //     return fib(n-1)+fib(n-2);
    // }

    // solution 3 recurisve with table
    //     int fib(int n){
    //         vector<int> memo(n+1,0);

    //         return help(memo,n);
    //     }
    //     int help(vector<int> &memo,int n){
    //         if (n==0 ||n==1){
    //             return n;
    //         }
    //         if (memo[n]!=0){
    //             return memo[n];
    //         }
    //         memo[n] = help(memo,n-1)+help(memo,n-2);
    //         return memo[n];
    //     }

    int fib(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};
int main()
{
    Solution solution;
    cout << solution.fib(3) << endl;
}
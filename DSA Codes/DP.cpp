#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// For solving DP questions, we can make a recursive function first of any compleity.
// Then we should use the ideas of this recursive function in Iterative solution

// Longest Common Subsequence

int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// Coin Change (Number of ways to obtain sum)

int getcount(int coins[], int n, int sum)
{
    int dp[sum + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1; // One way to obtain zero sum;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coins[j - 1] <= i)
            {
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[sum][n];
}

// Edit Distance problem (Convert string 1 into string 2 using minimum number of operations)
// Operations are 1> Insertion, 2> Deletion, 3> Replacement

int eD(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[m][n];
}

// Longest Increasing Subsequence

// (1) DP Based solution (O(n^2) -> Not the best approach)

int lis1(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = lis[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return res;
}

// (2) Binary Search Based solution (O(nlogn) -> Best approach)

int ceil_index(int tail[], int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return r;
}

int lis2(int arr[], int n)
{
    int tail[n], len = 1;
    //  tail[i]->Stores the minimum possible tail value for LIS of length (i+1)
    tail[0] = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceil_index(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

// Maximum Cuts

int maxcuts(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }
        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n];
}

// minimum jump to reach end

int minjumps(int arr[], int n)
{
    // arr[i]-> we can make a jump of 1 to arr[i] from ith index
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

// Knapsack

int knapsack(int w, int wt[], int val[], int n)
{
    int dp[n + 1][w + 1];
    // dp[i][j] -> Maximum value that we can collect with first i items and capacity j
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][w];
}

// Optimal strategy for a game
// Can pick only diagonal elements
// First we pick the computer then we then computer.....
// We need to make the maximum sum

// Recursive Solution
int sol1(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(sol1(arr, i + 2, j), sol1(arr, i + 1, j - 1)), min(sol1(arr, i + 1, j - 1), sol1(arr, i, j - 2)));
}

// DP solution
int sol2(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
}

// Egg Dropping puzzle -> Minimum number of trials for finding the Threshold floor

// Threshhold floor -> If we drop an egg from this floor then it breaks, but not from the floors below it
// Rules -> (1) Egg may break from 1st floor
//          (2) Egg may not break from the top floor
//          (3) If an egg breaks from a floor, it will break from upper floors also

// Recursive Solution
int eggDrop1(int n, int k)
{
    if (k == 1 || k == 0)
    {
        return k;
    }
    if (n == 1)
    {
        return k;
    }
    int min = INT_MAX, x, res;
    for (x = 1; x <= k; x++)
    {
        res = max(eggDrop1(n - 1, x - 1), eggDrop1(n, k - x));
        //             Break                 Doesn't Break
        if (res < min)
        {
            min = res;
        }
    }
    return min + 1;
}

// DP Solution
int res(int e, int f)
{
    int dp[f+1][e+1];
    for (int i=1; i<=e; i++)
    {
        dp[1][i]=1;
        dp[0][i]=0;
    }
    for (int j=1; j<=f; j++)
    {
        dp[j][1]=j;
    }
    for (int i=2; i<=f; i++)
    {
        for (int j=2; j<=e; j++)
        {
            dp[i][j]=INT_MAX;
            for (int x=1; x<=i; x++)
            {
                dp[i][j]=min(dp[i][j], 1+max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}

// BST's with n key
// Efficient Solution -> Ans for n is nth Catalan number i.e. ans=(2nCn/(n+1))

int countBSTs(int n)
{
    int dp[n+1];
    dp[0]=0;
    for (int i=0; i<=n; i++)
    {
        dp[i]=0;
        for (int j=0; j<i; j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

// Maximum sum with no two consecutives
// Can solve in O(1) space as well

int maxsum(int arr[], int n)
{
    if (n==1)
    {
        return arr[0];
    }
    int dp[n+1];
    dp[1]=arr[0];
    dp[2]=max(arr[0], arr[1]);
    for (int i=3; i<=n; i++)
    {
        dp[i]=max(dp[i-1], dp[i-2]+arr[i-1]);
    }
    return dp[n];
}

// Subset sum problem
// How many subsets have the given sum?

int count_subsets(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];
    for (int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }
    for (int j=1; j<=sum; j++)
    {
        dp[0][j]=0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            if (j<arr[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

signed main()
{
    cout << eD("aba", "cb", 3, 2) << endl;
}
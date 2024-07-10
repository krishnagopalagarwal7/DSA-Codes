#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define int long long

// Rabin Karp Algorithms: works in O(n) time, uses string hashing
vector<int> rabin_karp(string const &s, string const &t)
{
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }

    long long h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
        {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}

// longest proper prefix suffix array (LPS) -> Used in KMP Algorithm
vector<int> compute_LPS_array(string s)
{
    int n = (int)s.length();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = lps[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

// KMP Pattern search
void KMP(string pat, string txt)
{
    int n = txt.length(), m = pat.length();
    vector<int> lps = compute_LPS_array(pat);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            printf("Found pattern at index %d ", i - m);
            j = lps[m - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
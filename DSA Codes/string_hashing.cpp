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

const int p = 29;
const int m = 1e9 + 7;

long long compute_hash(string const &s, int n, vector<int> &hash, vector<int> &power)
{
    long long hash_value = 0;
    long long p_pow = 1;
    power[0] = 1;
    for (int i = 0; i < n; i++)
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        hash[i] = hash_value;
        p_pow = (p_pow * p) % m;
        power[i + 1] = p_pow;
    }
    return hash_value;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        if (n % 2 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<int> hash(n, 0), power(n + 1, 0);
            compute_hash(s, n, hash, power);
            string p = "", q = "";
            for (int i = 0; i < n / 2; i++)
            {
                p += s[i];
                q += s[n / 2 + i];
            }
            int answer = 0;
            if (p == q)
            {
                answer += 2;
            }
            int a, b, c, d;
            for (int i = 1; i < n / 2; i++)
            {
                a = hash[i - 1];
                b = (hash[2 * i - 1] - hash[i - 1] + m) % m;
                c = (hash[n / 2 + i - 1] - hash[2 * i - 1] + m) % m;
                d = (hash[n - 1] - hash[n / 2 + i - 1] + m) % m;
                if ((a * power[i]) % m == b && (c * power[n / 2 - i]) % m == d)
                {
                    answer++;
                }
            }
            cout << answer << endl;
        }
    }
    return 0;
}
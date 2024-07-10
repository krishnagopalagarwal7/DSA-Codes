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

struct Node
{
    vector<Node *> v;
    vector<int> for_finding;
    Node()
    {
        v.resize(26, nullptr);
        for_finding.resize(26, 0);
    }

    void insert(string s)
    {
        Node* current=this;
        if (current == NULL)
        {
            current = new Node();
        }
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (current->v[s[i] - 'a'] == NULL)
            {
                current->v[s[i] - 'a'] = new Node();
            }
            current = current->v[s[i] - 'a'];
        }
        current->for_finding[s[n - 1] - 'a']++;
    }

    bool find(string s)
    {
        Node *current=this;
        if (current == NULL)
        {
            return false;
        }
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (current->v[s[i] - 'a'] == NULL)
            {
                return false;
            }
            current = current->v[s[i] - 'a'];
        }
        if (current->for_finding[s[n - 1] - 'a'] == 0)
        {
            return false;
        }
        return true;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    Node *head = new Node();
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        head->insert(s);
    }
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> s;
        if (head->find(s) == true)
        {
            cout << s << " is present in the Trie" << endl;
        }
        else
        {
            cout << s << " is not present in the Trie" << endl;
        }
    }
}
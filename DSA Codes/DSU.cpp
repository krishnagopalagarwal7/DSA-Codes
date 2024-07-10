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

void initialize1(vector <int> &parent, int n)
{
    for (int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

void initialize2(vector <int>&parent, int n, vector <int>&rank)
{
    for (int i=0; i<n; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int find(int x, vector <int> &parent)
{
    if (parent[x]==x)
    {
        return x;
    }
    return find(parent[x], parent);
}

// Find with path compression
int find2(int x, vector <int>&parent)
{
    if (x==parent[x])
    {
        return x;
    }
    parent[x]=find2(parent[x], parent);
    return parent[x];
}

// Normal Union 
void union1(int x, int y, vector <int> &parent)
{
    int x_rep=find(x, parent);
    int y_rep=find(y, parent);
    if (x_rep==y_rep)
    {
        return;
    }
    parent[y_rep]=x_rep;
}

// Union by rank
void union2(int x, int y, vector <int>&parent, vector <int>&rank)
{
    int x_rep=find(x, parent);
    int y_rep=find(y, parent);
    if (x_rep==y_rep)
    {
        return;
    }
    if (rank[x_rep]<rank[y_rep])
    {
        parent[x_rep]=y_rep;
    }
    else if (rank[x_rep]>rank[y_rep])
    {
        parent[y_rep]=x_rep;
    }
    else
    {
        parent[y_rep]=x_rep;
        rank[x_rep]++;
    }
}

// Time complexity with Union by rank and Path Compression:
// For m operations on n elements
// O(m*alpha(n));
// where alpha(n) is inverse ackermann function
// alpha(n)<=4


signed main()
{
}
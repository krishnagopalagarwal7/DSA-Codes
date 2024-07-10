#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

vector<int> segtree;
void build(vector<int> &arr, int start, int end, int index) // Build the segment tree
{
    // Time Complexity: O(n)
    // n + n/2 + n/4 .... = 2*n
    if (start == end)
    {
        segtree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2, left = 2 * index, right = 2 * index + 1;
    build(arr, start, mid, left);    // go down left
    build(arr, mid + 1, end, right); // go down right
    segtree[index] = segtree[left] + segtree[right];
}

void update(vector<int> &arr, int start, int end, int index, int pos, int value) // Update at a given point in segment tree
{
    // Time Complexity: O(logn)
    if (start == end)
    {
        arr[pos] = value;
        segtree[index] = arr[pos];
        return;
    }
    int mid = (start + end) / 2, left = 2 * index, right = 2 * index + 1;
    if (mid >= pos)
    {
        update(arr, start, mid, left, pos, value);
    }
    else
    {
        update(arr, mid + 1, end, right, pos, value);
    }
    segtree[index] = segtree[left] + segtree[right];
}

int query(int start, int end, int index, int l, int r) // Give sum from L to R
{
    if (start>=l && end<=r) // Complete overlap // l...start....end....r
    {
        return segtree[index];
    }
    if (l > end || r < start) // Disjoint 
    {
        return 0;
    }
    int mid = (start + end) / 2, left = 2 * index, right = 2 * index + 1;
    int leftanswer = query(start, mid, left, l, r);
    int rightanswer = query(mid + 1, end, right, l, r);
    return leftanswer + rightanswer;
}

signed main()
{
    int n;
    cin >> n;
    segtree.resize(2 * n, -1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(arr, 0, n - 1, 1);
    for (int i=0; i<segtree.size(); i++)
    {
        cout << segtree[i] << " ";
    }
    cout << endl;
    for (int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << query(0, n-1, 1, 0, 3) << endl;



    update(arr, 0, n-1, 1, 1, 3);
    for (int i=0; i<segtree.size(); i++)
    {
        cout << segtree[i] << " ";
    }
    cout << endl;


    cout << query(0, n-1, 1, 0, 3) << endl;
}
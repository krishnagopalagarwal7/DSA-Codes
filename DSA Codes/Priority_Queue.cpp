#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    cout << "Max Heap" << endl;
    priority_queue<int> p;  // default for max heap
    p.push(10);
    p.push(15);
    p.push(5);
    // cout << p.top() << endl;
    cout << p.size() << endl;
    while(p.empty()==false)
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
    cout << "Min Heap" << endl;
    priority_queue<int, vector<int>, greater<int>> q; // for min heap, we have to pass an additional vector
    q.push(10);
    q.push(15);
    q.push(5);
    cout << q.size() << endl;
    while(q.empty()==false)
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    vector<int> v={10, 5, 15};
    priority_queue<int> r(v.begin(), v.end());
    cout << r.size() << endl;
    while(r.empty()==false)
    {
        cout << r.top() << " ";
        r.pop();
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

signed main()
{
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}
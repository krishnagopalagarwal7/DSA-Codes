#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Uses Red-Black tree in its Back-End.
    set<int> p;
    p.insert(10);
    p.insert(5);
    p.clear();
    p.insert(15);
    p.insert(10);
    p.insert(5);
    p.insert(15);
    p.insert(20);
    p.insert(25);
    p.insert(35);
    p.insert(40);
    cout << p.size() << endl;
    for (int x:p)
    {
        cout << x << " ";
    }
    cout << endl;
    // insted of p.begin() and p.end(), if we take p.rbegin() and p.rend(), then it will print in reverse.
    for (auto it=p.begin(); it!=p.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it=p.rbegin(); it!=p.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    auto it=p.find(10); //This iterator point to the value of 10;s
    cout << *it << endl;
    if (it==p.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    it=p.find(16);
    if (it==p.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
        p.erase(it);
    }
    p.erase(5);
    cout << p.size() << endl;
    if (p.count(10)==1)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }
    it=p.find(25);
    // p.erase(it, p.end());
    cout << p.size() << endl;
    it=p.lower_bound(10); // This function points to the element or if it is not present then it points to the element just larger than the element. Incase it is greater than the largest element, then it points to the s.end().
    // it exactly means the next key not necessarily greater or smaller.
    // Because we can have set in decreasing order so it gives the next key.
    cout << *it << endl;
    it=p.upper_bound(10); // All same as lower_bound but if the element is present then it points to the element just larger than the element.
    cout << *it << endl;
    // for reversing the order (To get in decreasing order)
    set<int, greater<int>> q;
    q.insert(10);
    q.insert(5);
    q.insert(15);
    for (int x:q)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto it=q.begin(); it!=q.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
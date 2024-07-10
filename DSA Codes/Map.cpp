#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Uses Red-Black trees in Back-End
    // Map and Set do not allow multiple value pair with same keys.
    map<int, int> m;
    m.insert({10, 200});
    m[5]=100;
    m.insert({3, 300});
    // if after the above line we try to insert {3, 400} or {3, 500} then it will not be inserted because there is already a key-value pair with the same key; 
    cout << m.size() << endl;
    cout << m[20] << endl; // We know that there is not a key-value pair with the given key. But if we call this line then it will form and store a new key-value pair with a default key. In int the default value is 0;
    cout << m.size() << endl;
    for (auto &x:m)
    {
        cout << x.first << " " << x.second << " " << endl;
    }
    m[3]=200; // value is updated.
    m.at(3)=100; // use to change the value of a key. But if the key is not present then it throws out of range exception;
    if (m.find(3)==m.end())
    {
        cout << "Not Present" << endl;
    }
    else
    {
        cout << "Present" << endl;
    }
    cout << "Krishna" << endl;
    for (auto it=m.find(5); it!=m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    if (m.count(3)==1)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    auto it=m.lower_bound(4); // Works same as in set.
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than orr equal present" << endl;
    }
    it=m.lower_bound(100);
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than or equal present" << endl;
    }
    it=m.lower_bound(10);
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than orr equal present" << endl;
    }
    it=m.upper_bound(4); // Works same as in set.
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than orr equal present" << endl;
    }
    it=m.upper_bound(100);
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than or equal present" << endl;
    }
    it=m.upper_bound(10);
    if (it!=m.end())
    {
        cout << (*it).first << endl;
    }
    else
    {
        cout << "No value greater than orr equal present" << endl;
    }
    cout << m.size() << endl;
    m.erase(5);
    cout << m.size() << endl;
    m.erase(m.find(20));
    cout << m.size() << endl;
    m.erase(m.find(3), m.end());
    cout << m.size() << endl;
    return 0;
}
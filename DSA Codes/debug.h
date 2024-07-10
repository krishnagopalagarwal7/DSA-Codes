// debug.h

#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>

using namespace std;
char nl = '\n';
char sp = ' ';
using ll = long long;
using vb = vector<bool>;
using vl = vector<ll>;
using vvb = vector<vb>;
using vvl = vector<vl>;
using sl = unordered_set<ll>;
using tsl = set<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using mll = map<ll, ll>;
using umll = unordered_map<ll, ll>;
using maxheap = priority_queue<ll>;                  // maxheap
using minheap = priority_queue<ll, vl, greater<ll>>; // minheap
using pqm = priority_queue<pll>;


///////////
template <typename L, typename R>
ostream &operator<<(ostream &out, const pair<L, R> &p)
{
    out << '[';
    out << '(' << p.first << ',' << p.second << ')';
    out << "]\n";
    return out;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &out, const tuple<T1, T2, T3> &tp)
{
    out << '[';
    auto &[t1, t2, t3] = tp;
    out << '(' << t1 << ',' << t2 << ',' << t3 << ')';
    out << "]\n";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    out << '[';
    for (auto &i : v)
        out << i << ' ';
    out << "]\n";
    return out;
}

template <typename T, size_t N>
ostream &operator<<(ostream &out, const array<T, N> &arr)
{
    out << '[';
    for (const auto &element : arr)
        out << element << ' ';
    out << "]\n";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, const set<T> &v)
{
    out << '[';
    for (auto &i : v)
        out << i << ' ';
    out << "]\n";
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_set<T> &v)
{
    out << '[';
    for (auto &i : v)
        out << i << ' ';
    out << "]\n";
    return out;
}

template <typename K, typename V>
ostream &operator<<(ostream &out, const map<K, V> &m)
{
    out << '[';
    for (auto &[k, v] : m)
    {
        out << k << ':' << v << sp;
    }
    out << "]\n";
    return out;
}

template <typename K, typename V>
ostream &operator<<(ostream &out, const unordered_map<K, V> &m)
{
    out << '[';
    for (auto &[k, v] : m)
    {
        out << k << ':' << v << sp;
    }
    out << "]\n";
    return out;
}

template<typename T>
istream& operator >>(istream& istream, vector<T>& v) {
    for(auto& element : v) {
        cin >> element;
    }
    return istream;
}

#endif // DEBUG_H


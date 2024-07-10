#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// To find the prime factorization
// O(sqrt(n)) time complexity
vector<int> factor(int n)
{
    vector<int> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        ret.push_back(n);
    }
    return ret;
}

// Count the number of divisors
// O(sqrt(n)) time complexity
int count_divisors(int n)
{
    int div_num = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                div_num += 1; // i and x/i are same, hence only one divisor;
            }
            else
            {
                div_num += 2; // There will be two divisors: i and x/i;
            }
        }
    }
    return div_num;
}

// Print all primes smaller than or equal to n
// O(nloglogn) time complexity
void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            {
                for (int i = p * p; i <= n; i += p)
                {
                    prime[i] = false;
                }
            }
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            cout << p << " ";
        }
    }
    cout << endl;
}

// Greatest common divisor
// O(logab) time complecity
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// Euler's totient function - written using phi(n) counts the number of positive integers in the interval [1,n] which are coprime to n.
// The totient function is multiplicative meaning that phi(nm)=phi(n)*phi(m)
// Let's take a look at some edge cases for phi(n):
// (1) If n is a prime number then phi(n)=n-1 because gcd(n, x)=1 for all 1<=x<=n
// (2) If n is a power of a prime number, n=p^q, where p is a prime number and q>=1 then there are exactly p^{q-1} numbers smaller
//     than n which are divisible by p, so phi(p^q)=p^{q} - p^{q-1} = (p^{q-1})(p - 1)

// For calculation phi(n)
// O(sqrt(n)) time complexity
int phi(int n)
{
    int ans = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }
            ans -= ans / p;
        }
    }
    if (n > 1)
    {
        ans -= ans / n;
    }
    return ans;
}

// For precomputation of phi(x), for all 1<=x<=n
// O(nloglogn) time complexity
// void precompute()
// {
//     for (int i = 1; i < MAX_N; i++)
//     {
//         phi[i] = i;
//     }
//     for (int i = 2; i < MAX_N; i++)
//     {
//         // If i is prime
//         if (phi[i] == i)
//         {
//             for (int j = i; j < NMAX; j += i)
//             {
//                 phi[j] -= phi[j] / i;
//             }
//         }
//     }
// }

signed main()
{
}
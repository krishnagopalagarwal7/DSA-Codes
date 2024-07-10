#include <iostream>
using namespace std;

// Using Iteration
int binary_search1(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            cout << "Element is present at index " << mid << endl;
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "Element is not present" << endl;
    return -1;
}

// Using Recursion
int binary_search2(int arr[], int n, int x, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
    {
        cout << "Number not found" << endl;
        return -1;
    }
    if (arr[mid] == x)
    {
        cout << "The index of numberr is " << mid << endl;
        return mid;
    }
    else if (arr[mid] > x)
    {
        return binary_search2(arr, n, x, low, mid - 1);
    }
    else
    {
        return binary_search2(arr, n, x, mid + 1, high);
    }
}

// First occurence of number using recursion
int binary_search3(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x > arr[mid])
    {
        return binary_search3(arr, mid + 1, high, x);
    }
    else if (x < arr[mid])
    {
        return binary_search3(arr, low, mid - 1, x);
    }
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
        {
            return mid;
        }
        else
        {
            return binary_search3(arr, low, mid - 1, x);
        }
    }
}

// First occurence of number using iteration
int binary_search4(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            high = mid - 1;
        }

        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
}

int main()
{
    int arr[10];
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * i;
    }
    binary_search1(arr, 10, 25);
    binary_search1(arr, 10, 24);
    binary_search2(arr, 10, 25, 0, n - 1);
    binary_search2(arr, 10, 24, 0, n - 1);
    return 0;
}
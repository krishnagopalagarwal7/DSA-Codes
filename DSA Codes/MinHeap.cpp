#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    ~MinHeap()
    {
        delete[] arr;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int x)
    {
        if (size == capacity)
        {
            return;
        }
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void minheapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
        {
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[smallest])
        {
            smallest = rt;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minheapify(smallest);
        }
    }

    int extractMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minheapify(0);
        return arr[size];
    }

    void decreasekey(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deletekey(int i)
    {
        decreasekey(i, -INT_MAX);
        extractMin();
    }
    // build heap function takes O(n) time not O(nlogn), n is size
    void build_min_heap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            minheapify(i);
        }
    }

    void maxheapify(int arr[], int n, int i)
    {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            maxheapify(arr, n, largest);
        }
    }

    void build_max_heap(int arr[], int n)
    {
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            maxheapify(arr, n, i);
        }
    }

    void heapsort(int arr[], int n)
    {
        build_max_heap(arr, n);
        for (int i = n - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);
            maxheapify(arr, i, 0);
        }
    }
};

int main()
{
    MinHeap krishna(10);
    krishna.insert(10);
    krishna.insert(20);
    krishna.insert(15);
    krishna.insert(40);
    krishna.insert(50);
    krishna.insert(100);
    krishna.insert(25);
    krishna.insert(45);
    krishna.print();
    krishna.heapsort(krishna.arr, krishna.size);
    for (int i = 0; i < krishna.size; i++)
    {
        cout << krishna.arr[i] << " ";
    }
    cout << endl;
}

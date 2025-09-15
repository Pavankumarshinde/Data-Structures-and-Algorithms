#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class heap
{
public:
    vector<int> arr;

    bool moveup(int i)
    {
        while (i > 0 && arr[(i - 1) / 2] <= arr[i])
        {
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
        return true;
    }

    bool movedown(int i)
    {
        while (2 * i + 1 < arr.size())
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < arr.size() && arr[left] > arr[largest])
                largest = left;
            if (right < arr.size() && arr[right] > arr[largest])
                largest = right;

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
                break;
        }
        return true;
    }

    bool heapify(vector<int> &array)
    {
        arr = array;
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            movedown(i);
        }
        return true;
    }

    heap(vector<int> array)
    {
        heapify(array);
    }

    bool push(int x)
    {
        arr.push_back(x);
        moveup(arr.size() - 1);
        return true;
    }

    bool pop()
    {
        if (arr.size() == 0)
            return false;
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        if (!arr.empty())
            movedown(0);
        return true;
    }

    int top()
    {
        if (arr.size() == 0)
            return -1;
        return arr[0];
    }

    void printHeap()
    {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    heap H(arr);

    cout << "Initial heap (max-heap): ";
    H.printHeap();

    cout << "Top element: " << H.top() << endl;

    cout << "After pushing 10:" << endl;
    H.push(10);
    H.printHeap();

    cout << "After popping top:" << endl;
    H.pop();
    H.printHeap();

    cout << "Current top: " << H.top() << endl;

    cout << "After pushing 7, 20, 15:" << endl;
    H.push(7);
    H.push(20);
    H.push(15);
    H.printHeap();

    cout << "Final top element: " << H.top() << endl;
}

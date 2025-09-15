#include <iostream>
#include <vector>
using namespace std;

class Queue
{
public:
    vector<int> arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int size;

    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = vector<int>(capacity);
        frontIdx = 0;
        rearIdx = -1;
        size = 0;
    }

    bool push(int x)
    {
        if (size == capacity)
        {
            return false; // full
        }
        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = x;
        size++;
        return true;
    }

    bool pop()
    {
        if (size == 0)
        {
            return false; // empty
        }
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return true;
    }

    bool front()
    {
        if (size == 0)
            return false;
        cout << arr[frontIdx] << endl;
        return true;
    }

    void printarr()
    {
        cout << "Queue state: ";
        if (size == 0)
        {
            cout << "empty" << endl;
            return;
        }
        for (int k = 0; k < size; k++)
        {
            cout << arr[(frontIdx + k) % capacity] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue Que(5);

    // Fill the queue
    cout << Que.push(10) << endl;
    cout << Que.push(20) << endl;
    cout << Que.push(30) << endl;
    cout << Que.push(40) << endl;
    cout << Que.push(50) << endl; // full → false

    Que.printarr();
    Que.front();

    // Remove two elements
    cout << Que.pop() << endl;
    cout << Que.pop() << endl;

    Que.printarr();
    Que.front();

    // Add more after popping
    cout << Que.push(60) << endl;
    cout << Que.push(70) << endl; // should succeed
    cout << Que.push(80) << endl; // should fail (full)

    Que.printarr();
    Que.front();

    // Empty completely
    while (Que.pop())
    {
        Que.front();
    }

    cout << "Final queue state:" << endl;
    Que.printarr();

    return 0;
}

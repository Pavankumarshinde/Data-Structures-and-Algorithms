#include<iostream>
#include<vector>

using namespace std;

class OpenAdd
{
private:
    int BUCKET;
    int size = 0;
    vector<int> table;

public:
    OpenAdd(int length);

    int h1(int key);
    int h2(int key);

    void linearProbing(int key);
    void quadraticProbing(int key);
    void doubleHashing(int key);

    void display();
};

OpenAdd :: OpenAdd(int length)
{
    this -> BUCKET = length;
    
    table.resize(BUCKET, 0);
}

int OpenAdd :: h1(int key)
{
    return (key % BUCKET);
}

int OpenAdd :: h2(int key)
{
    return ((BUCKET - 1) - (key % (BUCKET - 1)));
}

void OpenAdd :: linearProbing(int key)
{
    if (size == BUCKET)
    {
        cout << "Hashtable Overflow" << endl;
        return;
    }
    
    int index = h1(key);
    int i = 1;
    while (table[index] != 0)
    {
        index = (index + i)%BUCKET;
    }
    
    table[index] = key;
    size++;
}

void OpenAdd :: quadraticProbing(int key)
{
    if (size == BUCKET)
    {
        cout << "Hashtable Overflow" << endl;
        return;
    }
    
    int index = h1(key);
    int i = 1;
    while (table[index] != 0)
    {
        index = (index + i*i)%BUCKET;
        i++;
    }
    
    table[index] = key;
    size++;
}

void OpenAdd :: doubleHashing(int key)
{
    if (size == BUCKET)
    {
        cout << "Hashtable Overflow" << endl;
        return;
    }

    int probe = h1(key);
    int offset = h2(key);

    while (table[probe] != 0)
    {
        probe = (probe + offset)%BUCKET;
    }
    
    table[probe] = key;
    size++;
}

void OpenAdd :: display()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {49, 54, 56, 61, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // Linear Probing
    OpenAdd hash1(7);
    for (int i = 0; i < n; i++)
    {
        hash1.linearProbing(arr[i]);
    }
    cout << "Linear Probing:" << endl;
    hash1.display();

    // Quadratic Probing
    OpenAdd hash2(7);
    for (int i = 0; i < n; i++)
    {
        hash2.quadraticProbing(arr[i]);
    }
    cout << "\nQuadratic Probing:" << endl;;
    hash2.display();

    // Double Hashing
    OpenAdd hash3(7);
    for (int i = 0; i < n; i++)
    {
        hash3.doubleHashing(arr[i]);
    }
    cout << "\nDouble Hashing:" << endl;;
    hash3.display();
    return 0;
}
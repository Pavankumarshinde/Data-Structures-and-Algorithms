#include<iostream>
#include<list>

using namespace std;

class Hashing
{
private:
    int BUCKET;
    list<int> *table;

public:
    Hashing(int b);
    
    void insertItem(int key);
    void deleteItem(int key);
    void hashTable();
    int hashFunction(int key)
    {
        return key%BUCKET;
    }
};

Hashing::Hashing(int b)
{
    BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hashing::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hashing::deleteItem(int key)
{
    int index = hashFunction(key);
    
    list<int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            break;
        }
    }
    
    if (i != table[index].end())
    {
        table[index].erase(i);
    }
}

void Hashing::hashTable()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
        {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    Hashing h(7);
    for (int i = 0; i < n; i++)
    {
        h.insertItem(a[i]);
    }

    h.deleteItem(12);
    h.hashTable();
    return 0;
}

// (A) Time Complexity
// Search: O(1+(n/m))
// Delete: O(1+(n/m))
// where n = Total elements in hash table, m = Size of hash table
// Here n/m is the Load Factor ∝.
// Expected chain length: O(∝)
// Expected time to search: O(1 + ∝)
// Expected time to insert/delete: O(1 + ∝)

// (B) Auxiliary Space: O(1)
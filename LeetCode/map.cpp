#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<int, int> mymap;

    // insert({key, value}): Inserts a key-value pair.
    mymap.insert({1, 22});
    mymap.insert({2, 25});
    mymap.insert({4, 30});
    cout << "After inserts, size: " << mymap.size() << endl;

    // find(key): Finds an element by key.
    auto it = mymap.find(2);
    if (it != mymap.end()) {
        cout << "Found key 2 with value: " << it->second << endl;
    } else {
        cout << "Key 2 not found" << endl;
    }

    // at(key): Accesses the element by key with bounds checking.
    try {
        cout << "Value at key 1: " << mymap.at(1) << endl;
    } catch (const out_of_range& e) {
        cout << "Key 1 not found" << endl;
    }

    // operator[key]: Accesses or inserts the element by key.
    cout << "Value at key 4 using operator[]: " << mymap[4] << endl;

    // size(): Returns the number of elements.
    cout << "Size of map: " << mymap.size() << endl;

    // empty(): Checks if the map is empty.
    if (mymap.empty()) {
        cout << "Map is empty" << endl;
    } else {
        cout << "Map is not empty" << endl;
    }

    // erase(position): Removes an element by key.
    size_t erased_count = mymap.erase(2); // Remove key 2
    cout << "Erased key 2, count: " << erased_count << endl;
    cout << "Size after erasing key 2: " << mymap.size() << endl;

    // begin(): Returns an iterator to the beginning.
    // end(): Returns an iterator to the end.
    cout << "Elements in map:" << endl;
    for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // clear(): Removes all elements.
    mymap.clear();
    cout << "Size after clear: " << mymap.size() << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 5};
    myVector.insert(myVector.begin() + 3, 4); // Insert 4 at index 3
    for (int num : myVector) {
        cout << num << " ";
    }
    return 0;
}

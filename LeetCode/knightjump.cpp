#include <iostream>
#include <vector>

using namespace std;

struct node{
    int index;
    vector<node*> Nodes;
};

class Solution {
public:
    int number(vector<node>& array, int P, int n) {
        if (n == 0) {
            return 1;
        }
        if (array[P].Nodes.size() == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < array[P].Nodes.size(); i++) {
            sum += number(array, array[P].Nodes[i]->index, n - 1);
        }
        return sum;
    }

    int knightDialer(int n) {
        vector<node> array(10);
        for (int i = 0; i <= 9; i++) {
            array[i].index = i;
        }
        array[0].Nodes.push_back(&array[4]);
        array[0].Nodes.push_back(&array[6]);

        array[1].Nodes.push_back(&array[6]);
        array[1].Nodes.push_back(&array[8]);

        array[2].Nodes.push_back(&array[7]);
        array[2].Nodes.push_back(&array[9]);

        array[3].Nodes.push_back(&array[4]);
        array[3].Nodes.push_back(&array[8]);

        array[4].Nodes.push_back(&array[3]);
        array[4].Nodes.push_back(&array[9]);
        array[4].Nodes.push_back(&array[0]);

        array[6].Nodes.push_back(&array[1]);
        array[6].Nodes.push_back(&array[7]);
        array[6].Nodes.push_back(&array[0]);

        array[7].Nodes.push_back(&array[2]);
        array[7].Nodes.push_back(&array[6]);

        array[8].Nodes.push_back(&array[1]);
        array[8].Nodes.push_back(&array[3]);

        array[9].Nodes.push_back(&array[4]);
        array[9].Nodes.push_back(&array[2]);

        int sum = 0;
        for (int i = 0; i <= 9; i++) {
            sum += number(array, i, n - 1);
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int n = 3;
    cout << "Number of possible moves after " << n << " presses: " << sol.knightDialer(n) << endl;
    return 0;
}

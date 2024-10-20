#include <iostream>
#include <vector>

using namespace std;

void function(int index, vector<int> &array, vector<int> &subset)
{
    if (index == array.size())
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }
    // pick
    subset.push_back(array[index]);
    function(index + 1, array, subset);
    // not pick
    subset.pop_back();
    function(index + 1, array, subset);
    return;
}
class Solution
{
public:
    void subsequences(vector<int> &array)
    {
        vector<int> subset;
        function(0, array, subset);
    }
};
int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    Solution sol;
    sol.subsequences(array);
}
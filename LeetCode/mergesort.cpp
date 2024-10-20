#include <iostream>
#include <vector>

using namespace std;
vector<int> merge(vector<int> left, vector<int> right)
{
    int i = 0;
    int j = 0;
    vector<int> arr;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {

            arr.push_back(left[i]);
            i++;
        }
        else
        {
            arr.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        arr.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        arr.push_back(right[j]);
        j++;
    }
    return arr;
}
vector<int> divide(vector<int> arr)
{
    if (arr.size() == 1)
    {
        // cout << arr[0] << " ";
        return arr;
    }
    std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());
    return merge(divide(left), divide(right));
}
class Solution
{
public:
    vector<int> mergesort(vector<int> arr)
    {
        
        return divide(arr);
    }
};

int main()
{
    vector<int> arr = {2, 5, 1, 6, 1, 5, 9, 0, 2};
    Solution sol;
    arr = sol.mergesort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
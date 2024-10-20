#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int changes(string &s)
    {
        int x=0;
       
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='X')
            {
                x++;
            }
        }
        for(int i=0;i<s.size();i++)
        {
           

            for(int j=i;j<i+2*x;j++)
            {

            }

        }
        
    }

};

int main() {
    string s="X.XX.X..X";
    Solution sol;
    cout<<sol.changes(s);
    
    return 0;
}
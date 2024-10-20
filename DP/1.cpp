#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testcases;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;
        if(x>y)
        {
            cout<<y<<" "<<x<<endl;
        }
        else
        {
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}
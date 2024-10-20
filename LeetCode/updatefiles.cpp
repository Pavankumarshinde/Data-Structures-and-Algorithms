#include <iostream>
#include <vector>

using namespace std;
int main() {
    int testcases;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        int c,p;
        cin>>c>>p;
        if(c>1)
        {
            int j=1;
        int count=0;
        while(j<=p && j<c)
        {
            count++;
            j*=2;

        }
        while(j<c)
        {
            j+=p;
            count++;
        }
        cout<<count<<endl;

        }
        else{
            cout<<c-1<<endl;
        }
        

    }
    
    return 0;
}
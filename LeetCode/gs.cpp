#include <iostream>
#include <vector>

using namespace std;


void rightRotate(int & top, int & right, int & left)
{
    int temp=top;
    top= 7-right;
    right=temp;
    
}
void leftRotate(int & top,int & right, int & left)
{
    int temp=top;
    top=right;
    
    right=7-temp;
}
void downRotate(int & top, int & right,int & left)
{
    int temp=left;
    left=top;
    top=7-temp;
}
int main() {
    long long R;
    long long C;
    cin>>R;
    cin>>C;
    int top=1;
    int right=3;
    int left=2;
    
    int pre=0;
    for(int i=0;i<R;i++)
    {
        if(pre==0)
        {
            for(int j=0;j<C-1;j++)
            {
                cout<<top<<" ";
                rightRotate(top,right,left);

            }
            cout<<top<<" ";
            cout<<endl;
            pre=1;

        }
        else
        {
            for(int j=C-1;j>0;j--)
            {
                cout<<top<<" ";
                leftRotate(top,right,left);

            }
            cout<<top<<" ";
            cout<<endl;
            pre=0;

        }
        downRotate(top,right,left);
        
    }

    
    return 0;
}
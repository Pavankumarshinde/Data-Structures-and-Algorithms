#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if(a>b)
    {


    }
    else
    {
        int temp=b;
        b=a;
        a=temp;
    }
    int total=0;
    while(a>0 && b>0)
    {
        if(a==b)
        {
            break;
        }
        total++;
        
        int x=a-b;
        int y=b;
        if(x>y)
        {
            a=x;b=y;

        }
        else{
            b=x;
            a=y;
        }
        if(a==b)
        {
            break;
        }
        
      

    }
    cout<<total;
    return 0;
}


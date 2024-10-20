#include <iostream>
#include <vector>
#include<cmath>

using namespace std;
bool isprime(int num)
{
    if(num<=1)
    {
        return false;
    }
    if(num==2)
    {
        return true;
    }
    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i==0)
        {
            return true;
        }
    }
    return false;
}
int numberofprimefactors(int num)
{
    if(num==2)
    {
        return 1;
    }
    if(num==3)
    {
        return 1;
    }
    int i=2;
    int count=0;
    while(num!=1)
    {
        count++;
        while(num%i==0 && isprime(i))
        {
            
            num=num/i;
            

        }
        i++;
        
        
    }
    return count;
}
int main() {
    int n=10;
    // cin>>n;
    int count=0;
    
    for(int i=2;i<=n;i++)
    {
        if(numberofprimefactors(i)==2)
        {
            count++;
            

        }
        
        
    }
    cout<<count;
    
    
    return 0;
}
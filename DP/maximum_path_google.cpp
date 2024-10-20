#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;
bool prime(int n)
{
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

 int numberofprimefactors(int n)
    {
        map<int,int>mymap;
        int count=0;
        int N=n;
        for(int i=2;i<=N;i++)
        {
            if(mymap[i]==0 )
            {
                int condition=1;
                while(n%i==0 && prime(i))
                {
                    if(condition)
                    {
                        count++;
                        condition=0;
                    }
                    

                    // mymap[i]=1;
                    n=n/i;
                    // cout<<n<<" ";
                }

            }
            
        }
        return count;

}
int dp(vector<vector<int>> & grid,int i,int j)
{
    if(i==grid.size()-1 && j==grid.size()-1)
    {
        return 0;
    }
    int mini=4;
    int p=numberofprimefactors(grid[i][j]);
    for(int I=i;I<grid.size();I++)
    {
        for(int J=j;J<grid[0].size();J++)
        {
            
            if(abs(I-i)+abs(J-j)<=p )
            {
                if(!(I==i && J==j))
                {
                    mini= min(mini,sqrt(grid[i][j])+dp(grid,I,J));
         

                }
                
            }
            else
            {
                break;
            }
        }
        
        if(abs(I-i)>p)
        {
            break;
        }

    }
    return mini;

}
class Solution{
    public:
    int cost(vector<vector<int>> & grid)
    {
        return dp(grid,0,0);

    }

};

int main() {
    Solution sol;
    vector<vector<int>> grid={{13,12,15},{5,6,9},{2,4,8}};
    cout<<sol.cost(grid);
    return 0;
}
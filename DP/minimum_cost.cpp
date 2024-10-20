#include<iostream>
#include<vector>
// Given a N x M matrix, you are asked to find the minimum cost path from the top to the bottom. You can start at any column in the first row. If you are at point (i,j), you are constrained to move to only (i+1, j), (i+1, j-1), (i+1,j+1) in the next row.

using namespace std;

int dp(vector<vector<int>>&grid,vector<vector<int>>&data,int index,int used)
{
    if(index==0)
    {
        int mini=100000;
        for(int i=0;i<grid[0].size();i++)
        {
            if(i!=used && grid[index][i]<mini)
            {
                mini=grid[index][i];

            }
            // sum+=min;

        }
        return mini;
    }
    if(data[index][used]!=-1)
    {
        return data[index][used];
    }
    int mini=100000;
    for(int i=0;i<grid[0].size();i++)
    {
        if(i!=used)
        {
           int x= dp(grid,data,index-1,i)+ grid[index][i];
           mini=min(mini,x);

        }
        
    }
    return data[index][used]= mini;


}

class Solution{
    public:
    int minimumsum(vector<vector<int>>&grid)
    {
        vector<vector<int>> data(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        // int x=dp(grid,data,grid.size()-1,3);//memorization.


        // tabular
        

        // data[0][0]=grid[0][0];
        // data[0][1]=grid[0][1];
        // data[0][2]=grid[0][2];
        // data[0][3]=grid[0][3];
        // for(int i=1;i<grid.size();i++)
        // {
        //     for(int index=0;index<grid[0].size();index++)
        //     {
        //         // data[i][index]=;
        //         int mini=10000;
        //         for(int last=0;last<grid[0].size();last++)
        //         {
        //             if(last!=index)
        //             {
        //                 mini=min(mini,data[i-1][last]);
        //             }

        //         }
        //         data[i][index]=mini+grid[i][index];
        //         cout<<data[i][index]<<" ";
        



        //     }
        //     cout<<endl;
        // }
        // int mini=1000;
        // for(int i=0;i<grid[0].size();i++)
        // {
        //     mini=min(data[grid.size()-1][i],mini);

        // }
        


        vector<int> space_opti(grid[0].size()+1);
        space_opti[0]=grid[0][0];
        space_opti[1]=grid[0][1];
        space_opti[2]=grid[0][2];
        // space_opti[3]=grid[0][3];
        for(int i=1;i<grid.size();i++)
        {
            vector<int> temp(space_opti.size());
            for(int index=0;index<grid[0].size();index++)
            {
                // data[i][index]=;
                int mini=10000;
                
                for(int last=0;last<grid[0].size();last++)
                {
                    if(last!=index)
                    {
                        mini=min(mini,space_opti[last]);
                    }

                }
                // data[i][index]=mini+grid[i][index];
                // space_opti[index]=mini+grid[i][index];
                temp[index]=mini+grid[i][index];
                cout<<temp[index]<<" ";
                
        



            }
            space_opti=temp;
            cout<<endl;
        }
        int mini=1000;
        for(int i=0;i<grid[0].size();i++)
        {
            mini=min(space_opti[i],mini);

        }

        
        return mini;

        // return data[grid.size()][grid[0].size()];


    }
};
int main()
{
    Solution sol;
    vector<vector<int>> grid={ { 2, 1, 3 }, { 3, 4, 6 }, { 10, 1, 6 },{8,3,7} };
    cout<<sol.minimumsum(grid);

    return  0;

}

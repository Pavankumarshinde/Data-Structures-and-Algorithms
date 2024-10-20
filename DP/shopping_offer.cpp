#include<iostream>
#include<vector>

using namespace std;
int dp(vector<vector<int>>& special,int index,vector<int> &collection,vector<int>& needs,vector<int>& price)
{
    if(index==special.size())
    {
        // print
        bool Return=true;
        for(int i=0;i<collection.size()-1;i++)
        {
            
            if(needs[i]>=collection[i])
            {
                collection[collection.size()-1]+=price[i]*(needs[i]-collection[i]);
                
            }
            else
            {
                return 10000;
                Return =false;

            }
            
        }
        
        if(Return==true)
        {
            return collection[collection.size()-1];
        }
        else
        {
            return 10000;
        }
        
        
    }
    // pick
    for(int i=0;i<collection.size()-1;i++)
    {
        collection[i]+=special[index][i];
        
    }
    collection[collection.size()-1]+=special[index][collection.size()-1];
    int x=dp(special,index+1,collection,needs,price);
    
    


    // dontpick;
    for(int i=0;i<collection.size()-1;i++)
    {
        collection[i]-=special[index][i];
        
    }
    collection[collection.size()-1]-=special[index][collection.size()-1];
    int y=dp(special,index+1,collection,needs,price);

    return min(x,y);
}
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<int> collection(needs.size()+1,0);
        int x=dp(special,0,collection,needs,price);
        return x;
        
    }
};
int main()
{
    Solution sol;
    vector<int> price={2,5}; 
    vector<vector<int>> special={{3,0,5},{1,2,10}};
    vector<int> needs={3,2};
   cout<< sol.shoppingOffers(price,special,needs);

}
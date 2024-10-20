#include <iostream>
#include <vector>
#include<queue>
#include<cmath>

using namespace std;
struct cir{
    int x;
    int y;
    int r;
    int flag;
};
class Solution{
    public:
    bool circle_connets(vector<vector<int>> circle)
    {
        vector<cir> Array(circle.size());
        for(int i=0;i<Array.size();i++)
        {
            cir P;
            P.x=circle[i][0];
            P.y=circle[i][1];
            P.r=circle[i][2];
            P.flag=true;
            Array[i]=P;
        }
        queue<cir>Que;
        Que.push(Array[0]);
        Array[0].flag=false;
        while(!Que.empty())
        {
            cir Current=Que.front();
            Que.pop();
            for(int i=0;i<Array.size();i++)
            {
                if(Array[i].flag && Array[i].r+Current.r >=sqrt((Array[i].x -Current.x )*(Array[i].x -Current.x ) +(Array[i].y -Current.y )*(Array[i].y -Current.y )))
                {
                    Array[i].flag=false;
                    Que.push(Array[i]);
                }
            }
        }
        
        for(int i=0;i<Array.size();i++)
        {
            if(Array[i].flag==true)
            {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    vector<vector<int>> circle = {
    {0, 0, 2}, {1, 1, 2}, {2, 2, 2}, {3, 3, 2}, {4, 4, 2}, {5, 5, 2}, {6, 6, 2}, {7, 7, 2}
};
Solution sol;
    cout<<sol.circle_connets(circle);

                                

    
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int solve(int numCom, int cables){
    int updated = 1;
    int time = 0;
    while (updated < numCom )
    {
        if (updated <= cables)
        {
            updated+=updated;
            time++;
        }
        else{
            updated+=cables;
            time++;
        }
        
    }
    return time; 
}

int main(){
    int t;
    cin>>t;

    while(t>0){
        int numCom,cables;
        cin>>numCom;
        cin>>cables;
        int ans=solve(numCom,cables);
        cout<<ans<<" ";
        t--;
    }

    return 0;
}
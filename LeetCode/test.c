#include <bits/stdc++.h>

using namespace std;

int function(int numCom, int cables){
    int updated = 1;
    int time = 0;
    while (updated <= numCom )
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
        cin>>numCom>>cables;
        int ans=function(numCom,cables);
        cout<<ans<<" ";
        t--;
    }

    return 0;
}
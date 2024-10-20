#include<bits/stdc++.h>

using namespace std;

void binary_cut(){
    int i=0,j=1,k=0;

    string s;
    cin>>s;
   // cout<<s;


    while(i<s.size()-1){
        if(s[i]!=s[i+1]){
            if(s[i]=='0' && s[i+1]=='1'){
                k++;
            }
            j++;
        }
        i++;
    }
    if(k>0){
        j=j-1;
    }

    cout<<j<<endl;


}

int main(){
    int i=0,j=0;
    int n;
    cin>>n;
    while(i<n){
        binary_cut();
        i++;
    }
    
    return 0;
}
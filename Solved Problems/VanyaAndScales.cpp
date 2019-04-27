#include <bits/stdc++.h>

using namespace std;

int main(){
long long w=0,m=0;
cin>>w>>m;
vector<int>v(200+9);
int idx=0;

while(m)
    v[idx++]=m%w,m/=w;

for(int i=0;i<=50;i++){
if(v[i]>1){
        if(v[i]==w-1||v[i]==w)v[i]=0,v[i+1]++;
        else{cout<<"NO";return 0;}
        }


}

cout<<"YES";



    return 0;
}

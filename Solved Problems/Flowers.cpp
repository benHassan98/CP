#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7,MAX=100000+9;
int k=0;
long long dp[MAX];
long long solve(int i){
if(!i)return 1;
if(i<0)return 0;
long long &ans=dp[i];
if(ans!=-1)return ans;

return ans=((solve(i-1)%MOD)+(solve(i-k)%MOD))%MOD;
}
int main(){
int t=0;
cin>>t>>k;
memset(dp,-1,sizeof dp);
vector<long long>pre(1,0);
vector<long long>v;
for(int i=1;i<MAX;i++)pre.push_back(   solve(i) +  pre.back()   );


while(t--){
int a=0,b=0;
cin>>a>>b;

v.push_back(   pre[b]-pre[a-1]   );
}
for(int i=0;i<(int)v.size();i++)cout<<v[i]%MOD<<"\n";



    return 0;
}

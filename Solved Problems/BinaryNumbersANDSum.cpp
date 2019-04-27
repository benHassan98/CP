#include <bits/stdc++.h>

using namespace std;
const int MOD=998244353;
int power[200000+8]={0};
int main(){
power[0]=1;
for(int i=1;i<200000+5;i++)
    power[i]=(power[i-1]*2)%MOD;
long long n=0,m=0,ans=0,ones=0;
string a="",b="";
cin>>n>>m;
cin>>a>>b;
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
for(int i=0;i<m;i++)ones+=(b[i]=='1');

for(int i=0;i<min(n,m);i++){
    if(a[i]=='1')
      ans=((ans%MOD)+(  (ones%MOD)*(power[i]%MOD)        )%MOD)%MOD;

ones-=(b[i]=='1');
}

cout<<ans%MOD;


    return 0;
}

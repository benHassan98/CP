#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const MOD=1e9+7;

vector<ll>zeros;
void NcR(ll z){
vector<ll>denum;
while(z)denum.push_back(z--);
for(ll i=0;i<(ll)denum.size();i++){
 for(ll j=0;j<(ll)zeros.size();j++){
    ll g=__gcd(denum[i],zeros[j]);
    denum[i]/=g;
    zeros[j]/=g;
 }

}

denum.clear();

}
int main(){
vector<ll>ones;
vector<ll>diff;
long long n=0,m=0,ans=1;
cin>>n>>m;
for(ll i=0;i<m;i++){ll x=0;cin>>x;ones.push_back(x);}
sort(ones.begin(),ones.end());
for(ll i=n-m;i>0;i--)zeros.push_back(i);

for(ll i=1;i<(ll)ones.size();i++)diff.push_back(ones[i]-ones[i-1]-1);

NcR(ones[0]-1);
for(ll i=1;i<(ll)ones.size();i++){NcR(ones[i]-ones[i-1]-1);}
NcR(n-ones[ones.size()-1 ]);

for(ll i=0;i<(ll)zeros.size();i++)ans=((ans%MOD)*(zeros[i]%MOD)%MOD);

for(ll i=0;i<(ll)diff.size();i++){
    for(ll j=1;j<diff[i];j++)ans=((ans%MOD)*(2%MOD)%MOD);
}
cout<<ans;


    return 0;
}

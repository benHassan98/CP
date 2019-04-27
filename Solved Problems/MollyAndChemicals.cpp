#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll const OO=1e15;
int main(){
ll ans=0,n=0,k=0,w=1;
map<ll,vector<ll> >freq;
ll arr[100000]={0};
ll sum[100000+9]={0};
ios::sync_with_stdio(false);
cin>>n>>k;
for(int i=0;i<n;i++)cin>>arr[i];
sum[0]=arr[0];
freq[sum[0] ].push_back(0);
for(int i=1;i<n;i++){sum[i]=(sum[i-1]+arr[i]);freq[ sum[i] ].push_back(i);}

for(int z=0;z<50;z++,w*=k){
if(w>=OO)break;
if(k==1&&z)break;
if(k==-1&&z>1)break;
ans+=freq[w].size();

for(int i=1;i<n;i++){
ll val=w+sum[i-1];
int l=0,r=freq[val].size()-1,idx=-1;
while(l<=r){
int mid=(l+r)/2;
if(freq[val][mid]<i)l=mid+1;
else r=mid-1,idx=mid;
}
if(idx!=-1)ans+=freq[val].size()-idx;


}




}
cout<<ans;

    return 0;
}

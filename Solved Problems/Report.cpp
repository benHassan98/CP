#include <bits/stdc++.h>

using namespace std;
vector<int>v;
vector<int>ts;
const int N=200000;
int cnt[N]={0};
int main(){
int maxr=0;
int n=0,m=0;
int arr[N]={0};
cin>>n>>m;
for(int i=0;i<n;i++)cin>>arr[i];
for(int i=0;i<m;i++){
int t=0,r=0;
cin>>t>>r;
ts.push_back(t);
maxr=max(r,maxr);
cnt[r-1]=i;
}
int val=-1;
for(int i=N-1;i>=0;i--)
    if(cnt[i]>val)val=cnt[i];
    else cnt[i]=val;

for(int i=0;i<maxr;i++)v.push_back(arr[i]);
sort(v.begin(),v.end());
int s=0,e=v.size()-1;
for(int i=maxr-1;i>=0;i--){
int t=ts[  cnt[i] ];
if(t==1)arr[i]=v[e--];
else arr[i]=v[s++];
}
for(int i=0;i<n;i++)cout<<arr[i]<<" ";


    return 0;
}

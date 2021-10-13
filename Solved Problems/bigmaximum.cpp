#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e18;

int bstsuff(vector<int>v){
int ans = -1e8;
int suff=0;
for(int i=v.size()-1;i>=0;i--){
suff+=v[i];
ans = max(ans,suff);
}
return ans;
}
int bstpref(vector<int>v){
int ans = -1e8;
int pref=0;
for(int i=0;i<v.size();i++){
  pref+=v[i];
  ans = max(ans,pref);
}

return ans;
}
int main() {
int n=0,m=0,l=0;
int sum [60]={0};
int best[60][60]={0};
int arr[250009];
long long dp[250009];
bool vis[60]={0};
long long cur_sum[60]={0};
long long ans = -OO;
vector<vector<int> > v;

vector<int>vt;
cin>>n>>m;
for(int i=0,x=0,s=0;i<n;i++){
  cin>>l;
  while(l--){
    cin>>x;
    vt.push_back(x);
    s+=x;
  }
sum[i] = s;
v.push_back(vt);
vt.clear();
s=0;
}
for(int i=0,x=0;i<m;i++)cin>>arr[i];
for(int k=0;k<n;k++){
vector<int>pref;
int s = -1e9;
pref.push_back(v[k][0]);
for(int j=1;j<v[k].size();j++)pref.push_back(pref.back()+v[k][j] );
for(int i=0;i<v[k].size();i++)
for(int j=i;j<v[k].size();j++){
int x = pref[j];
if(i-1>=0)x-=pref[i-1];
s = max(s,x);
}
vt.push_back(s);
}
for(int i=0;i<n;i++)for(int j=0;j<n;j++){

int suff = bstsuff(v[i]);
int pref = bstpref(v[j]);

best[i][j] = max( {pref,suff,pref+suff  } );
}
for(int i=0;i<m;i++){
int indx = arr[i]-1;

dp[i] = vt[indx];
for(int j=0;j<n;j++)
if(vis[j])
dp[i] = max( dp[i], cur_sum[j]+best[j][indx] );


for(int j=0;j<n;j++)
if(vis[j]&&j!=indx)
cur_sum[j] += sum[indx];

if(vis[indx])
cur_sum[indx] = max(cur_sum[indx]+sum[indx],0ll);

ans = max(ans,dp[i]);
vis[indx]=1;
}




cout<<ans<<"\n";
  return 0;
}

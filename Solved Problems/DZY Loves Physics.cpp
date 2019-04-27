#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >adj[501];
bool vis[501];
int val[501];
double ans=0;
void DFS(int node,int V,int E){
vis[node]=1;
double maxx=0;
pair<int,int>sol;
for(int i=0;i<(int)adj[node].size();i++){
if(vis[adj[node][i].first])continue;
double x=((V+val[adj[node][i].first])*1.0)/((E+adj[node][i].second)*1.0);
if(x>maxx){
 sol=adj[node][i];
 maxx=x;
}

}
if(sol.first!=0){
ans=max(ans,maxx);
V+=val[sol.first];
E+=sol.second;
DFS(sol.first,V,E);
}

}
int main(){
int n=0,m=0;
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)scanf("%d",&val[i]);
for(int i=0;i<m;i++){
int a=0,b=0,c=0;
scanf("%d%d%d",&a,&b,&c);
adj[a].push_back({b,c});
adj[b].push_back({a,c});
}
for(int i=1;i<=n;i++){
DFS(i,val[i],0);

memset(vis,0,sizeof vis);
}
cout<<setprecision(15)<<fixed<<ans;

    return 0;
}

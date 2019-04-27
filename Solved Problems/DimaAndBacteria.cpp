#include <bits/stdc++.h>

using namespace std;
vector<int>type;
vector<  vector< pair<int,int> > >adj(100000);
const int OO=1e9;
int d[600][600]={0};
bool vis[100000+1]={0};
map<int,int>tmap;
void DFS(int node){
vis[node]=1;
tmap[ type[node]  ]++;
for(int i=0;i<(int)adj[node].size();i++)
    if(!vis[ adj[node][i].first  ]&&!adj[node][i].second)DFS(adj[node][i].first);
}


int main(){
for(int i=0;i<600;i++)for(int j=0;j<600;j++)d[i][j]=OO;
int n=0,m=0,k=0,psum=0,csum=0;
vector<int>start;
vector<int>typefreq;
cin>>n>>m>>k;
for(int i=0;i<k;i++){
    int x=0;cin>>x;
    start.push_back(psum);
    typefreq.push_back(x);
    csum+=x;
    while(psum<csum)type.push_back(i),psum++;

}
while(m--){
    int a=0,b=0,c=0;
    cin>>a>>b>>c;
    adj[a-1].push_back(make_pair(b-1,c));
    adj[b-1].push_back(make_pair(a-1,c));
    d[ type[a-1] ][ type[b-1]  ]=min(d[ type[a-1] ][ type[b-1]  ],c);
    d[ type[b-1] ][ type[a-1]  ]=min(d[ type[b-1] ][ type[a-1]  ],c);
}
for(int i=0;i<k;i++){
if(vis[ start[i] ])continue;
DFS(start[i]);
for(auto it:tmap)if(typefreq[it.first]!=it.second){cout<<"No\n";return 0;}

tmap.clear();

}

for(int i=0;i<k;i++)
    for(int j=0;j<k;j++)
       if(i==j)d[i][j]=0;



for(int z=0;z<k;z++)
    for(int i=0;i<k;i++)
       for(int j=0;j<k;j++)
            d[i][j]=min(d[i][j],d[i][z]+d[z][j]);

cout<<"Yes\n";
for(int i=0;i<k;i++){for(int j=0;j<k;j++)cout<<(d[i][j]==OO?-1:d[i][j])<<" ";cout<<"\n";}








    return 0;
}

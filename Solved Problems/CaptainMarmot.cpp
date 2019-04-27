#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector< vector< pair<pair<ll,ll>,pair<ll,ll> >  > >reg(100+1);
bool vis[4]={0};

const ll OO=1e15;
ll ans=OO;
bool check(int k){
vector<ll> dis;
for(int i=0;i<4;i++){
ll x=reg[k][i].first.first,y=reg[k][i].first.second;
for(int j=i+1;j<4;j++){
ll x2=reg[k][j].first.first,y2=reg[k][j].first.second;
ll d=((x-x2)*(x-x2))+((y-y2)*(y-y2));
dis.push_back(d);

   }
}
sort(dis.begin(),dis.end());
if(!dis[0])return 0;
bool f=1;
for(int i=1;i<4;i++)f&=(dis[0]==dis[i]);
f&=(dis[4]==dis[5])&&(dis[5]==2*dis[0]);
return f;
}
void pos(int i,int j=0,ll cnt1=0){
if((int)reg[i].size()==j){

         if(check(i))ans=min(ans,cnt1);

        return;
}
ll cnt2=0;
for(int k=0;k<4;k++){

ll x=reg[i][j].first.first,y=reg[i][j].first.second;
ll a=reg[i][j].second.first,b=reg[i][j].second.second;

pos(i,j+1,cnt1+cnt2);

int x_=-(y-b)+a,y_=(x-a)+b;

reg[i][j]=make_pair(make_pair(x_,y_)   ,make_pair(a,b)    );

cnt2++;
}


}



int main(){
int n=0;
vector<int>v;
cin>>n;
for(int i=1;i<=n;i++)
    for(int j=0;j<4;j++){
int x=0,y=0,a=0,b=0;
cin>>x>>y>>a>>b;
reg[i].push_back(make_pair ( make_pair(x,y)   ,make_pair(a,b)   ) );


    }



for(int i=1;i<=n;i++){
 pos(i);
v.push_back(ans==OO?-1:ans);
ans=OO;
}
for(int i=0;i<(int)v.size();i++)cout<<v[i]<<endl;
    return 0;
}

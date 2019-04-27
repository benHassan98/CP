#include <bits/stdc++.h>

using namespace std;

int main(){
vector<long long>V;
map<pair<long long,long long>,long long>edge_cost;
int q=0;
cin>>q;
while(q--){
long long t=0,u=0,v=0,w=0;
set<long long>st1;
set<long long>st2;
vector<long long>P;
cin>>t>>u>>v;

while(u>0)st1.insert(u),u/=2;
while(v>0)
    if(st1.find(v)==st1.end())st2.insert(v),v/=2;
    else break;
set<long long>:: reverse_iterator it=st2.rbegin();
while(it!=st2.rend()){P.push_back(*it);it++;}
set<long long>:: iterator it2=st1.find(v);
while(it2!=st1.end()){P.push_back(*it2);it2++;}
if(t==1){
cin>>w;
for(int i=1;i<(int)P.size();i++)edge_cost[make_pair(P[i],P[i-1])]+=w,edge_cost[make_pair(P[i-1],P[i])]+=w;

}
else{

long long ans=0;
for(int i=1;i<(int)P.size();i++)ans+=edge_cost[make_pair(P[i-1],P[i])  ];

V.push_back(ans);

}




}

for(int i=0;i<(int)V.size();i++)cout<<V[i]<<"\n";


    return 0;
}

#include <bits/stdc++.h>

using namespace std;
vector<int>KS;
vector<pair<int,int> >v;
int shots[200000+9]={0};
int main(){
vector<int>ans;
int n=0,a=0,b=0,k=0;
string str="";
cin>>n>>a>>b>>k;
cin>>str;
KS.push_back(-1);
for(int i=0;i<n;i++){
    if(str[i]=='1')KS.push_back(i);
}
KS.push_back(n);
for(int i=1;i<(int)KS.size();i++){
int l=KS[i-1]+1,r=KS[i]-1;
if(l>r||r-l+1<b)continue;
v.push_back(make_pair(r-l+1,l));
}


sort(v.begin(),v.end());


while(a){
int f=v.back().first;
if(a>f/b)a-=(f/b),v.pop_back();
else {v.back().first-=(a*b);break;}
}

for(int z=0;z<(int)v.size();z++){

for(int i=v[z].second,j=v[z].second+b-1;j<v[z].first+v[z].second;i++,j++)shots[i]++,shots[j+1]--;

for(int i=v[z].second+1;i<v[z].first+v[z].second;i++)shots[i]+=shots[i-1];

int i=v[z].second,j=b+v[z].second;
int maxx=0,idx=-1;
while(j<=v[z].first+v[z].second){
if(shots[i]>=maxx){maxx=shots[i],idx=i;}
i++;

if(i==j){ans.push_back(idx);i=idx+1;j=i+b;idx=-1;maxx=0;}
}






}

ans.push_back( v.back().second+v.back().first+(a*b)-b      );



cout<<ans.size()<<"\n";
for(int i=0;i<(int)ans.size();i++)cout<<ans[i]+1<<" ";




    return 0;
}

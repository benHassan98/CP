#include <bits/stdc++.h>

using namespace std;
char g[1000][1000];
int main(){
int n=0,a=0,b=0,c=0,d=0;
for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)g[i][j]='.';
cin>>a>>b>>c>>d>>n;
vector<int>v(n,0);
for(int i=0;i<n;i++)cin>>v[i];
for(int i=0;i<b;i++)
    for(int j=0;j<a;j++)g[i][j]='v';

for(int i=0;i<d;i++)
    for(int j=a;j<a+c;j++)g[i][j]='v';




if(b>d){
int t=((b-d)%2==0?1:-1);
for(int i=b-1;i>=0;i--,t*=-1){

 for(int j=( t>0?0: i<d? a+c-1:a-1 );j>=0 ; j+=t,v.back()-- ){
    if(g[i][j]=='.')break;
    if(!v.back())v.pop_back();
    g[i][j]=((char)('a'+(v.size()-1)));

 }

}

       }
else{
int t=((d-b)%2==0?-1:1);

for(int i=d-1;i>=0;i--,t*=-1){

 for(int j=( t<0?a+c-1: i<b? 0:a ); j>=0; j+=t,v.back()-- ){
    if(g[i][j]=='.')break;
    if(!v.back())v.pop_back();
    g[i][j]=((char)('a'+(v.size()-1)));

 }

}





}
cout<<"YES\n";
for(int i=0;i<max(d,b);i++){
    for(int j=0;j<a+c;j++)cout<<g[i][j];
cout<<"\n";
}


    return 0;
}

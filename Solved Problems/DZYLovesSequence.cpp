#include <bits/stdc++.h>

using namespace std;

int main(){
int ans=0,n=0;
int arr[100000]={0};
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];

int pre=-1;
bool change=0;
vector<int>v;
for(int i=0,j=0;j<n;j++){

if(!v.size())v.push_back(arr[j]);
else if(v[v.size()-1]<arr[j])v.push_back(arr[j]);
else if(!change){
if(v.size()==1)v[v.size()-1]=arr[j]-1,v.push_back(arr[j]);
else if(v.size()>=2&&v[v.size()-2]<arr[j]-1)v[v.size()-1]=arr[j]-1,v.push_back(arr[j]);
else v.push_back(v[v.size()-1]+1);
change++;
pre=j;
}
else{
    v.clear();
    change=0;
    i=j=pre;
    v.push_back(arr[pre]);
}

ans=max(ans,(j-i+1)+(i>0&&!change));
}




cout<<ans;
    return 0;
}

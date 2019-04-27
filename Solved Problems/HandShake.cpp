#include <bits/stdc++.h>

using namespace std;

int main(){
int n=0,p=0;
vector<int>ans;
vector< queue<int>   >v(300001);
cin>>n;
for(int i=1;i<=n;i++){
    int x=0;
    cin>>x;
v[x].push(i);
}
while(p>=0){
if(v[p].size()){
ans.push_back(v[p].front());
v[p].pop();
p++;
}
else{
p-=3;
}


}
if((int)ans.size()!=n)cout<<"Impossible";
else{
    cout<<"Possible\n";
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}


    return 0;
}

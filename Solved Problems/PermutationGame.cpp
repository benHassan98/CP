#include <bits/stdc++.h>

using namespace std;
int dp[100009][4]={0};
int n=0;
int arr[100005]={0};
int solve(int i,bool turn=0){
int &ans=dp[i][turn];
if(ans!=-1)return ans;

bool ON=0,OFF=0;
for(int j=arr[i];;j+=arr[i]){
    if(i+j>n&&i-j<1)break;

    int c1=-1,c2=-1;

    if(i+j<=n&&arr[i+j]>arr[i])c1=solve(i+j,turn^1);
    if(i-j>0&&arr[i-j]>arr[i])c2=solve(i-j,turn^1);
ON+=(c1>0||c2>0);
OFF+=(c1==0||c2==0);
}
if(turn){
    if(OFF)ans=0;
    else ans=1;
}
else{
    if(ON)return ans=1;
    else ans=0;
}


return ans;

}



int main(){
memset(dp,-1,sizeof dp);

cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];

for(int i=1;i<=n;i++)cout<<(solve(i)?"A":"B");


    return 0;
}

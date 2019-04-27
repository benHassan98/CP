#include <bits/stdc++.h>

using namespace std;
double ax=0,ay=0,bx=0,by=0,tx=0,ty=0;
long long n=0;
const int N=100000+9;
const double OO=1e30;
vector<double>A,B,T;
double dp[N][2][2];
double solve(int i=0,bool p1=0,bool p2=0){
if(i==n)return (p1||p2?0:OO);
double &ans=dp[i][p1][p2];
if(ans==ans)return ans;
ans=OO;
if(!p1)ans=min(ans,solve(i+1,1,p2)+A[i]);
if(!p2)ans=min(ans,solve(i+1,p1,1)+B[i]);
ans=min(ans,solve(i+1,p1,p2)+T[i]);
return ans;

}

int main(){
double arr[100000][2]={0};
//for(int i=0;i<N;i++)for(int k=0;k<2;k++)for(int z=0;z<2;z++)dp[i][k][z]=-1;
memset(dp,-1,sizeof dp);
cin>>ax>>ay>>bx>>by>>tx>>ty;
cin>>n;

for(int i=0;i<n;i++){
cin>>arr[i][0]>>arr[i][1];
double va=((ax-arr[i][0])*(ax-arr[i][0])+(ay-arr[i][1])*(ay-arr[i][1]));
double vb=((bx-arr[i][0])*(bx-arr[i][0])+(by-arr[i][1])*(by-arr[i][1]));
double vt=((tx-arr[i][0])*(tx-arr[i][0])+(ty-arr[i][1])*(ty-arr[i][1]));
va=sqrt(va)+sqrt(vt);
vb=sqrt(vb)+sqrt(vt);
vt=sqrt(vt)+sqrt(vt);
A.push_back(va);
B.push_back(vb);
T.push_back(vt);
}
cout<<setprecision(6)<<fixed<<solve();






    return 0;
}

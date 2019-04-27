#include <bits/stdc++.h>

using namespace std;
const int N=1e7+5;
int arr[N]={0};
vector<bool>isPrime(N,1);
int main(){
 for (int i = 2; i*i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= N; j += i)
                isPrime[j] = 0;
        }
    }


cout<<"INput"<<endl;
int n=1e6,m=0;
vector<int>vr;
scanf("%d",&n);
while(n--){
int x=1e7+5;
scanf("%d",&x);
for(int i=2;i*i<=x;i++){
    bool f=0;
while(x%i==0)x/=i,f=1;
arr[i]+=f;
}
if(x>1)arr[x]++;



}

for(int i=1;i<N;i++)arr[i]+=arr[i-1];
scanf("%d",&m);
while(m--){
int l=0,r=0,ans=0;
scanf("%d%d",&l,&r);
l=min(l,N-1);
r=min(r,N-1);
ans+=arr[r];
if(l-1>=1)ans-=arr[l-1];
vr.push_back(ans);

}
for(int i=0;i<(int)vr.size();i++)printf("%d\n",vr[i]);


    return 0;
}

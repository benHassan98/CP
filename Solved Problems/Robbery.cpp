#include <bits/stdc++.h>

using namespace std;

const long long OO=1e9;
int main(){
long long n=0,m=0,k=0,e=OO;
int arr[10000]={0};
cin>>n>>m>>k;
for(int i=0;i<n;i++){cin>>arr[i];e=min(e,arr[i]+(i%2)*OO);}
if(n%2==0||m<n-(n/2)){cout<<0;return 0;}
long long cost=n-(n/2);
cout<<min((m/cost)*k,e);


    return 0;
}

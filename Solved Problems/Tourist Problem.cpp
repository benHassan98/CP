#include <bits/stdc++.h>

using namespace std;
long long arr[100000+9]={0};
long long sum[100000+9]={0};
int main(){
long long n=0,s=0;
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
sort(arr,arr+n);
sum[0]=arr[0];
for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+arr[i]);

for(long long i=n-1;i>0;i--)
    s+=((i*arr[i])-(sum[i-1]));
s*=2;


long long num=s+sum[n],denum=n;
long long g=__gcd(num,denum);
num/=g,denum/=g;
cout<<num<<" "<<denum;


    return 0;
}

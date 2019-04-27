#include <bits/stdc++.h>

using namespace std;

int main(){
int n=0,k=0,ians=1e6;
int freq[10]={0};
string str="",sans="";

for(int i=0;i<1e4+9;i++)sans+='9';
cin>>n>>k;
cin>>str;
for(int i=0;i<n;i++)freq[ str[i]-'0' ]++;
for(int num=0;num<10;num++){
string res2=str;
int chosen[10]={0};
int x=max(0,k-freq[num]),res=0;

for(int i=num+1,j=num-1;(i<10||j>=0)&&x;i++,j--){
if(i<10){if(freq[i]){res+=(abs(i-num)*min(x,freq[i]));chosen[i]=min(freq[i],x);x-=min(x,freq[i]);} }
if(j>=0){if(freq[j]&&x){res+=(abs(j-num)*min(x,freq[j]));chosen[j]=min(freq[j],x);x-=min(x,freq[j]);} }

}
if(!x){
for(int i=0;i<10;i++){
  if(!chosen[i])continue;
  if(i>num){for(int j=0;j<n&&chosen[i];j++)if(res2[j]-'0'==i)res2[j]=num+'0',chosen[i]--;}
  else {for(int j=n-1;j>=0&&chosen[i];j--)if(res2[j]-'0'==i)res2[j]=num+'0',chosen[i]--;}

}


if(res<ians)ians=res,sans=res2;
else if(res==ians&&res2<sans)sans=res2;

}



}
cout<<ians<<endl<<sans;


    return 0;
}

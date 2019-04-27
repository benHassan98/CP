#include <bits/stdc++.h>

using namespace std;
const int MAX=30;
int main(){
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
string s="",t="";
int z=0,n=0;
int freq_s[MAX]={0},freq_t[MAX]={0};
int over[MAX]={0};
int need[MAX]={0};
queue<char>Q;
cin>>s>>t;
n=s.length();
for(int i=0;i<n;i++)freq_s[ s[i]-'A'  ]++,freq_t[ t[i]-'A' ]++;


for(int i=0;i<MAX;i++)
if(freq_s[i]<freq_t[i])z+=freq_t[i]-freq_s[i],need[i]=freq_t[i]-freq_s[i];
else if(freq_s[i]>freq_t[i])over[i]=freq_s[i]-freq_t[i];

for(int i=0;i<MAX;i++)while(need[i]--)Q.push(((char)(i+'A')));


for(int i=0;i<n;i++){
if(!over[ s[i]-'A'  ]){continue;freq_s[ s[i]-'A' ]--;}
char let=s[i];
if(s[i]<Q.front()&&freq_s[ s[i]-'A' ]==over[ s[i]-'A' ])over[ s[i]-'A' ]--,s[i]=Q.front(),Q.pop();
else if(s[i]>Q.front())over[ s[i]-'A' ]--,s[i]=Q.front(),Q.pop();
freq_s[let-'A']--;
}



cout<<z<<"\n"<<s;

    return 0;
}

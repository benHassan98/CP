#include <bits/stdc++.h>

using namespace std;

int main(){
int n=0,cnt=0,ians=0;
int arr[100000+9]={0};
string str="",sans="",buf="";
cin>>str;
n=str.length();
stack<pair<char,int> >st;
for(int i=0;i<n;i++){
if(str[i]=='('||str[i]=='[')st.push(make_pair(str[i],i));
else {
bool correct=0;
if(st.size())correct=((str[i]==')'&&st.top().first=='(')||(str[i]==']'&&st.top().first=='['));
if(!correct){
if(st.size())arr[st.top().second]=arr[i]=-1;
else arr[i]=-1;
while(st.size()){arr[st.top().second]=-1;st.pop();}
}
else st.pop();
}


}

while(st.size()){arr[st.top().second]=-1;st.pop();}

for(int i=0;i<n;i++){
if(arr[i]==-1){
if(!st.size()){
    if((cnt>ians)||(cnt==ians&&buf.length()>sans.length()))ians=cnt,sans=buf;
}
while(st.size())st.pop();
buf="";
cnt=0;
continue;
}
buf+=str[i];
if(str[i]=='('||str[i]=='[')cnt+=(str[i]=='['),st.push(make_pair(str[i],i));
else st.pop();
}
if(!st.size()){
        if((cnt>ians)||(cnt==ians&&buf.length()>sans.length()))ians=cnt,sans=buf;
}
cout<<ians<<endl<<sans;


    return 0;
}

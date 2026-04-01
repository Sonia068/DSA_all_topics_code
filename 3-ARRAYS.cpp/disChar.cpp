//<-------Count Distinct Characters in a String-------->
#include <iostream>
#include <string>
using namespace std;

int countString(string s){
    int count=0;
    int vis[256]={0}; // Assuming ASCII character set

  for(int i=0;i<s.length();i++){
    // index= s[i]; // Get ASCII value of character
      if(vis[s[i]]==0){
          vis[s[i]]=1;
          count++;
      }
    }
    return count;
}


int main(){
    string s;
    cout<<"Enter a string:";
//    getline(cin,s);
    cin>>s;

    int t=countString(s);
    cout<<"Count of distinct characters is:"<<t;
return 0;
}
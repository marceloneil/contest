#include <iostream>
#include <set>
#include <cstring>//memset
using namespace std;
int main(){
  int n;
  cin>>n;
  set<string> dict;
  while (n--){
    string temp;
    cin>>temp;
    dict.insert(temp);
  }
  int v = 1;
  while(v--){
    string word;
    cin>>word;
    int wl = word.size();
    int dp[wl+2][wl+2];
    memset(dp,0,sizeof dp);

    for(int s = 1; s< wl; s++){
      for(int l = 0; l + s < wl+1; l++){
        //if the substring within the range is a word then make that index in the dp 1
        if(dict.count(word.substr(l,l+s+1)) != 0 ){
          cout<<"rip"<<endl;
          dp[l+1][l+s+1] = 1;
        }else{
          cout<<"hi"<<endl;
          for(int p = 0; p +1< s;p++){
            if(dict.count(word.substr(l,l+p+1)) != 0 && dict.count(word.substr(l+p+1,l+s+1)) != 0){
              dp[l+1][l+s+1] =dp[l][l+p] + dp[l+p+1][l+s+1];
            }
          }
        }
      }
    }
    for(int i = 0 ; i < 5;i++){
      for(int a = 0; a < 5;a++){
        cout<<to_string(dp[i][a]) + " ";
      }
      cout<<endl;
    }


    /*
    for(int s = 0; s < wl; s++){
      for(int l = 0; l + s < wl; l++){
        if(dict.count(word.substr(l,l+s+1)) != 0 ){
          dp[l+1][l+s+1] = 1;
        }else{
          cout<<"hi"<<endl;
          for(int p = 0; p < wl;p++){
            if(dict.count(word.substr(l,l+p+1)) != 0 && dict.count(word.substr(l+p+1,l+s+1)) != 0){
              dp[l+1][l+s+1] =
            }
          }
          dp[l+1][l+s+1] = dp[l+1][l+s] + dp[l + 2][l+s+1];
          cout<<dp[l+1][l+s+1]<<endl;
        }
      }
    }*/
    cout<<dp[1][wl]<<endl;
  }
}

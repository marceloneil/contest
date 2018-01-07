#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int a,w;
vector< pair<int,int>> cats;

template<typename T>
void pop_front(std::vector<T>& vec)
{
    if(!vec.empty()){
      vec.erase(vec.begin());
    }
}

/*void findCuteness(){
  int dp[w + 3];
  int n = cats.size();
  memset(dp,0,sizeof(dp));
  for(int i = 1; i <=n;i++){
    for(int j = w; j >= cats[i].first; j--){
      dp[j] = max(dp[j],dp[j-cats[i].first] + cats[i].second);
    }
  }
  cout<<dp[w+1];
}*/
void findCuteness(){
  int n = cats.size();
  int dp[n][w];
  for(int i =0 ; i < n;i++){
    for(int j = 0; j < w;j++){
      dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= w; j++){
      if (j < cats[i].first) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-cats[i].first] + cats[i].second);
    }
  }
  cout<<dp[n][w]<<endl;
}



int main(){
  cin>>a>>w;
  while(a--){
    string cat;
    int p,c;
    cin>>cat;
    if(cat == "A"){
      cin>>p>>c;
      cats.push_back( make_pair(p,c));
      findCuteness();
    }else{
      pop_front(cats);
    }
  }
}

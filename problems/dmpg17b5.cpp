//solve this dp problem like you wouldw fibonnachi numbers. dp[i] = max(val[i], dp[i-1]);
#include <iostream>
#include <queue>
using namespace std;
int dp[1000005];
priority_queue<pair<int,int> > arr;
int main(){
  int n,q;
  cin>>n;
  for(int i = 0;i<n;i++){
    int temp1, temp2;
    cin>>temp1>>temp2;
    arr.push(make_pair(temp2,temp1));
  }
  //time = c, wow = v
  while(!arr.empty()){
    pair<int,int> hi;
    hi = arr.top();
    arr.pop();
    for(int i =hi.second;i<1000005;i++){
      if(hi.second > dp[i]){
        dp[i] = hi.first;
      }else{
        break;
      }
    }
  }
  cin>>q;
  for(int i = 0; i < q; i++){
    int query;
    cin>>query;
    cout<<dp[query]<<endl;
  }

}

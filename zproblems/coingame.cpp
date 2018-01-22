#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
using namespace std;

vector<vector<int> > dp;
vector<vector<int> > sum;

int solve(int l, int r){
  if (dp[l][r]) return dp[l][r];
  if (l == r) dp[l][r] = sum[r]-sum[l-1];
  else dp[l][r] = sum[r]-sum[l-1]-min(solve(l+1,r),solve(l,r-1));
  return dp[l][r];
}
int main(){
  int N = 5;
cout<<solve(1,N)<<endl;
}

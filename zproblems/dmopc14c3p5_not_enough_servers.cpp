#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ll long long
#define US (unsigned)
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MN 100005

int dp[1048578][30];
bool arr[22][32];
int n,m;
int fullMask;
pair<int,VI> calc(int mask, int cur){ // returns the minimum test cases to select
  cout<<mask<<endl;
  if(mask == fullMask) return {0,vector<int>()};
  if(cur == m+1) return{INF,vector<int>()};
  // use this testcase
  int newMask = mask;
  for(int i = 1; i<=n;i++){
    if(arr[i][cur]){
      newMask |= (i<<i);
    }
  }
  pair<int,VI> ans1 = calc(newMask,cur+1);
  ans1.F+=1;
  ans1.S.PB(cur);
  //skip this testcase
  pair<int,VI> ans2 = calc(mask,cur+1);
  if(ans1.F < ans2.F){
    return ans1;
  }return ans2;
}
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  cin>>n>>m;
  fullMask = (1<<n)-1;
  for(int i = 1; i<=n;i++){
    string temp;
    cin>>temp;
    for(int a = 0; a<m;a++){
      if(temp.at(a) == 'X'){
        arr[i][a+1] = 1;
      }
    }
  }
  pair<int,VI> ans = calc(0,1);
  cout<<ans.F<<endl;
  for(int i = 0;i<ans.F;i++){
    cout<<ans.S[i]<<endl;
  }
}

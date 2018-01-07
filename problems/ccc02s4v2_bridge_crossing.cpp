#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int m,q;
string names[103];
int arr[103];
int dp[103];
int maxs[103][103];
pair<int,int> groups[103];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>m>>q;
  for(int i = 1; i <=q;i++){
    cin>>names[i]>>arr[i];
  }
  for(int i= 1;i<=q;i++){
    int lastMax = -1;
    for(int a = i; a <=q;a++){
      if(arr[a] > lastMax){
        maxs[i][a] = arr[a];
        lastMax = arr[a];
      }else{
        maxs[i][a] = lastMax;
      }
    }
  }
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <=q;i++){
    for(int a = 1; a <=m;a++){
      if(i >= a){
        if(dp[i] > dp[i-a] + maxs[i-a + 1][i]){
          dp[i] = dp[i-a] + maxs[i-a + 1][i];
          groups[i] = {i-a+1,i};
        }
      }
    }
  }
  stack<string> ans;
  cout<<"Total Time: " + to_string(dp[q])<<endl;
  int nextIdx = q;
  while(nextIdx != 0){
    pair<int,int> theRange = groups[nextIdx];
    string curAns = "";
    for(int i = theRange.F; i <=theRange.S;i++){
      curAns+=names[i] + " ";
    }
    ans.push(curAns);
    nextIdx = theRange.F-1;
  }
  while(!ans.empty()){
    cout<<ans.top()<<endl;
    ans.pop();
  }
}

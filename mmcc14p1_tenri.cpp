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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

//the dp array is given these boxes left over and these sprinkers, what is the max
int fullMask;
int b[13], dp[2050][13][17]; // current mask and current box
int n,x;

int calc(int mask,int box, int s){
  // s represents sprinklers I have left
  //the mask represents boxes I haven't used yet
  if(dp[mask][box][s] != -1) return dp[mask][box][s];
  if(mask == fullMask){
    return dp[mask][box][s] = ((b[box] + s) * (b[box] + s)) + s;
  }
  // I have to loop through every combination of a pair of boxes. Above that I have to loop through all the combinations of sprinklers as well.


  int best = 0;
  for(int i = 0;i<n;i++){
    // if I didn't use this box
    if(!(mask & (1<<i))){
      int tempMask = mask | (1<<i);
      for(int a = 0; a <n;a++){
        if(!(tempMask & (1<<a))){
          tempMask |= (1<<a);
          for(int d = 0; d <=s;d++){
            int valOfCurBox = (b[box] + s - d) * (b[box] + s - d); // NOTE I DIDN'T ADD 'S'
            //if(tempMask != fullMask){
              for(int o = 0; o <=d;o++){
                valOfCurBox = min(valOfCurBox, calc(tempMask, i,o) * calc(tempMask, a,d-o));
              }
            //}
            best = max(best, valOfCurBox + s - d);
          }
        }
      }
    }
  }
  cout<<best<<endl;
  return dp[mask][box][s] = best;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>x;
  for(int i = 1; i <=n;i++){
    cin>>b[i];
  }
  fullMask = (1<<n)-1;
  memset(dp,-1,sizeof dp);
  int maxAns = 0;
  for(int i = 0;i<n;i++){
    maxAns = max(maxAns,calc(1<<i,i,x));
  }
  cout<<maxAns<<endl;
}

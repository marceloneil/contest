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

int h[51], e[51], p[51];
PII dp[51][1005]; // F = max happiness , S = minTime;
// the arr means: how much happiness can you generate given this teacher and this time
int n;

PII calc(int teacher, int ttime){
  if(ttime <= 0) return {0,0};
  if(teacher > n) return {0,0};
  if(dp[teacher][ttime].F != -1){
    return dp[teacher][ttime];
  }
  int ansMaxHappiness = 0;
  int ansMinTime = 0;
  // this entire loop needs t be redone. like wtf what are you doing. i-1 .... I think you're going into the negative
  for(int i = 0; h[teacher] - ((i-1) * e[teacher]) > 0 && (i) * p[teacher] <= ttime; i++){ // the number of times the teacher appears
    //int happiness = (i+1/2) * (2*h[teacher] - ((i+1) * e[teacher]));
    int happiness = 0;
    for(int a = 0; a <i;a++){
      happiness+= (h[teacher] - (e[teacher] * a));
    }
    //cout<<h[teacher]<<" "<<i<<" "<<e[teacher]<<" "<<p[teacher]<<" "<<happiness<<endl<<endl;
    PII otherTeachers = calc(teacher + 1, ttime - ((i) * p[teacher]));
    happiness += otherTeachers.F;

    if(happiness > ansMaxHappiness){
      ansMaxHappiness = happiness;
      ansMinTime = otherTeachers.S + i;
    }else if(happiness == ansMaxHappiness){
      ansMinTime = min(ansMinTime, otherTeachers.S + i);
    }
  }
  dp[teacher][ttime] = {ansMaxHappiness, ansMinTime};
  return {ansMaxHappiness, ansMinTime};
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int s;
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>h[i]>>e[i]>>p[i];
  }
  cin>>s;
  memset(dp, -1, sizeof dp);
  PII ans = calc(0, s);
  cout<<ans.F<<endl;
  cout<<ans.S<<endl;
}

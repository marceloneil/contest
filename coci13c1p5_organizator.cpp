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

int clubs[200004];
int n,maxPpl;
ll ans;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.sync_with_stdio(0);
  cout.tie(0);
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>clubs[i];
    maxPpl = max(maxPpl, clubs[i]);
  }
  // finals size = teamsize * number of cs clubs;
  // if teamsize = 4 and num teams of teamsize = 2 is 5, there cannot be more than 5 clubs with teamsize 4
  for(int teamsize = 1; teamsize <=maxPpl;teamsize++){
    int clubCount = 0;
    for(int i = 1;i<=n;i++){
      if(clubs[i]%teamsize == 0){
        clubCount++;
      }
    }
    if(clubCount > 1){
      if(clubCount*teamsize > ans){
        ans = clubCount*teamsize;
      }
    }
  }
  cout<<ans;
}

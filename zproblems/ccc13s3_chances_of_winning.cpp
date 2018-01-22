#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
//#define aall(x) x, x + n // #define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005

bool gamesDone[6];
VPII games = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};

//needs work
int calc(int index, int score){
  if(gamesDone[index]) calc(index+1, score);
  if(index == 5) return 0;

  return score;
}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int t,g;
  cin>>t>>g;
  for(int i = 1; i<=g;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int lo = min(a,b);
    int hi = max(a,b);
    for(int i = 0;i<6;i++){
      if(games[i] == MP(lo,hi)){
        gamesDone[i] = 1;
        break;
      }
    }
  }
  cout<<calc(0,0)<<endl;
}

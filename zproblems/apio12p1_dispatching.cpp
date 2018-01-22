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
// for each ninja, what is the maximum number of ninjas I can dispatch given cost.
// I can place all lower ninjas in a priority queue and as I ascend the tree
// I can pop off ninjas that are too expensive if I find cheaper ones.
// 2 arrays: 1 num ninjas and 2 cost

int n,m,c[100005],l[100005],totc[100005];

priority_queue<int> ninjas[100005]; // top = most costly

// I am disatisfied with how I can't get the back of a priority_queue
// that is why I am taking a break from solving this problem.

int maxNinjas(int cur){
  for(int nd : ninjas[cur]){
    // if(ninjas[nd].top())
    if(curNinja + totc[cur] <= m){
      totc[c]+=curNinja;
    }
    if(curNinja < ninjas[cur].top()){
      ninjas[cur].pop();
      ninjas[cur].push(curNinja);
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=n;i++){
    int a;
    cin>>a>>c[i]>>l[i];
    ninjas[a].push(c[i]);
  }
  //assign all ninjas as bosses
  int ans = -1;
  for(int i = n; i > 0;i++){ // note how lower ninjas have a higher i
    ans = max(ans, l[i]*maxNinjas(i));
  }
  cout<<ans<<endl;
}

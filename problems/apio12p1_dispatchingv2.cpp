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

int n,m,b[100005],c[100005],l[100005];

priority_queue<int> ninjas[100005]; // top = most costly


void combine(int a,int b){
  if(ninjas[a].size() > ninjas[b].size()){
    swap(ninjas[a],ninjas[b]);
    swap(c[a],c[b]);
  }
  while(!ninjas[a].empty()){
    c[b]+=ninjas[a].top();
    ninjas[b].push(ninjas[a].top());
    ninjas[a].pop();
  }
  while(c[b] > m){
    c[b]-=ninjas[b].top();
    ninjas[b].pop();
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=n;i++){
    cin>>b[i]>>c[i]>>l[i];
    ninjas[b[i]].push(c[i]);
  }
  //assign all ninjas as bosses
  int ans = -1;
  for(int i = n; i > 0;i++){ // note how lower ninjas have a higher i
    ans = max(ans, l[i]*(int)ninjas[i].size());
    combine(i,b[i]);
  }
  cout<<ans<<endl;
}

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

int n,m;
int amount[300005];
vector<int> edges[300005];

/*
int minCanMake(int root){
  if(edges.empty()){
    return amount;
  }
  for(int nxt : edges[root]){

  }
}*/

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    int tar;
    cin>>tar;
    int temp;
    cin>>temp;
    int temp2;
    for(int a = 1;a<=temp;a++){
      cin>>temp2;
      edges[tar].PB(temp2);
    }
  }
  for(int i = 1;i<=n;i++){
    cin>>amount[i];
  }
  ll ans = amount[1]; // he has to at least take this number of items first
  amount[1] = 0;
  if(!edges[1].empty()){
    // remove the minimum recipe items
    while(produceOne(1)){
      ans++;
    }
  }

  cout<<ans<<endl;
}

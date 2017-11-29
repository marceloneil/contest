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

bool inDegree[1000005];
bool alreadyPushed[1000005];
int n,m;
struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
vector<int> ans;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <=m;i++){
    int a,b;
    cin>>a>>b;
    if(inDegree[a] == 1){
      if(!alreadyPushed[a]){
        ans.push_back(a);
        alreadyPushed[a] = 1;
      }
    }else{
      inDegree[a]++;
    }
    if(inDegree[b] == 1){
      if(!alreadyPushed[b]){
        ans.push_back(b);
        alreadyPushed[b] = 1;
      }
    }else{
      inDegree[b]++;
    }
  }
  sort(ans.begin(), ans.end(),greater1());
  cout<<ans.size()<<endl;
  while(!ans.empty()){
    cout<<ans.back()<<endl;
    ans.pop_back();
  }
}

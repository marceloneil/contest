#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
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


void findLongestPath(int start, int ){

}



int n,t,costOfTree;
int edges[200005][200005];
int inDegree[200005],start[200005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(int i = 1; i <=t;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges[a][b] = c;
    edges[b][a] = c;
    inDegree[a] += 1;
    inDegree[b] += 1;
    costOfTree+=c;
    //increase then return
    if(++inDegree[a] == t){
      start[a] = 1;
    }else{
      start[a] = 0;
    }
    if(++inDegree[b] == t){
      start[b] = 1;
    }else{
      start[b] = 0;
    }
  }
  costOfTree = costOfTree * 2;
  for(int i = 1; i <=n;i++){
    if(inDegree[i] == t){

    }
  }
}

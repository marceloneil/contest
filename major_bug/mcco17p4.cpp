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

int n,m;
bool status[200005];
int indegree[200005];
int indegreea[200005];
vector<int> edges[200005];
//if all the edge nodes can't be taken out


queue<int> Q;
queue<int> Q2;
int curType = 1;
void filter(){
  while(!Q.empty()){
    int v = Q.front();Q.pop();
    if(status[v] == curType){
      for(int nd: edges[v]){
        if( --indegree[nd] == 0 ){
          Q.push(nd);
        }
      }
    }else{
      Q2.push(v);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0 ; i<n;i++){
    int temp;
    cin>>temp;
    status[i] = temp+1;
  }
  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    indegree[b]+=1;
    indegreea[b]+=1;
  }

  for(int i = 1; i<=n;i++){
    if(indegree[i] == 0 ){
      Q.push(i);
    }
  }
  int ans = 0;
  while(!Q.empty()){
    filter();

    //switching weapons
    if(curType == 1){
      curType = 2;
    }else{
      curType = 1;
    }
    if(!Q2.empty()){
      ans++;
    }

    //purging the Q2 stack and then decreasing the indegrees of its children
    while(!Q2.empty()){
      cout<<"hi"<<endl;
      int val = Q2.front();Q2.pop();
      for(int nd: edges[val]){
        if( --indegree[nd] == 0 ){
          Q.push(nd);
        }
      }
    }
  }

//now we do the same thing but start on the second type
int ans2 = 0;




  cout<<ans<<endl;
}

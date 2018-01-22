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
queue<int> Q3;
queue<int> Q4;
int curType = 0;
void filter(){
  while(!Q.empty()){
    int v = Q.front();Q.pop();
    if(status[v] == curType){
      for(int nd: edges[v]){
        indegree[nd]--;
        if(indegree[nd] == 0 ){
          Q.push(nd);
        }
      }
    }else{
      Q2.push(v);
    }
  }
}

void filter2(){
  while(!Q3.empty()){
    int v = Q3.front();Q3.pop();
    if(status[v] == curType){
      for(int nd: edges[v]){
        indegreea[nd]--;
        if(indegreea[nd] == 0 ){
          Q3.push(nd);
        }
      }
    }else{
      Q4.push(v);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0 ; i<n;i++){
    cin>>status[i];
  }
  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    indegree[b]+=1;
    indegreea[b]+=1;
  }

  for(int i = 0; i<n;i++){
    if(indegree[i] == 0 ){
      Q.push(i);
      Q3.push(i);
    }
  }
  int ans = 0;
  while(!Q.empty()){
    filter();

    //switching weapons
    if(curType == 0){
      curType = 1;
    }else{
      curType = 0;
    }
    //purging the Q2 stack and then decreasing the indegrees of its children
    if(!Q2.empty()){
      ans++;
    }
    while(!Q2.empty()){
      int val = Q2.front();Q2.pop();
      Q.push(val);
    }
  }
  curType = 1;
  int ans2 = 0;
  while(!Q3.empty()){
    filter2();

    //switching weapons
    if(curType == 0){
      curType = 1;
    }else{
      curType = 0;
    }
    //purging the Q2 stack and then decreasing the indegrees of its children
    if(!Q4.empty()){
      ans2++;
    }
    while(!Q4.empty()){
      int val = Q4.front();Q4.pop();
      Q3.push(val);
    }
  }

  //now we do the same thing but start on the second type
  cout<<min(ans,ans2)<<endl;
}

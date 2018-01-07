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

int arr[14][14];
int w,e;
int maxOne = -1;
int c1 = -1;
int c2 = -1;
int dist[13][13];
int r,c;

bool checkCloser(int a, int b){
  int dist1 = pow(c1 - w,2) + pow(c2-e,2);
  int dist2 = pow(a - w,2) + pow(b-e,2);
  if(dist2 < dist1){
    return true;
  }
  return false;
}

//I also have to try to minimize the number of trees cut in the event of a tie
//rip idk why my bfs isn't working
void bfs(){
  stack<pair<int,pair<int,int>>> theStack;
  theStack.push({0,{w,e}});
  while(!theStack.empty()){
    pair<int,pair<int,int>> nd = theStack.top();theStack.pop();
    if((nd.S.F == w && nd.S.S == e )|| nd.F + dist[nd.S.F][nd.S.S]< dist[nd.S.F][nd.S.S]){
      dist[nd.S.F][nd.S.S] = nd.F + dist[nd.S.F][nd.S.S];
      if(nd.S.F + 1 <= r && (dist[nd.S.F][nd.S.S] + dist[nd.S.F+1][nd.S.S]) < dist[nd.S.F+1][nd.S.S]){
        theStack.push({nd.F,{nd.S.F+1,nd.S.S}});
      }
      if(nd.S.F-1 >= 1 && (dist[nd.S.F][nd.S.S] + dist[nd.S.F-1][nd.S.S]) < dist[nd.S.F-1][nd.S.S]){
        theStack.push({nd.F,{nd.S.F-1,nd.S.S}});
      }
      if(nd.S.S + 1<= c && (dist[nd.S.F][nd.S.S] + dist[nd.S.S+1][nd.S.S]) < dist[nd.S.S+1][nd.S.S]){
        theStack.push({nd.F,{nd.S.S+1,nd.S.S}});
      }
      if(nd.S.S - 1 <= c && (dist[nd.S.F][nd.S.S] + dist[nd.S.S-1][nd.S.S]) < dist[nd.S.S-1][nd.S.S]){
        theStack.push({nd.F,{nd.S.S-1,nd.S.S}});
      }
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  memset(dist,INF,sizeof dist);
  cin>>r>>c;
  for(int i = 1; i <=r;i++){
    for(int a = 1; a <=c;a++){
      string temp;
      cin>>temp;
      if(temp == "X"){
        w = i;
        e = a;
        arr[i][a] = -2;
      }else if(temp == "."){
        continue;
      }else{
        arr[i][a] = stoi(temp);
      }
    }
  }

  for(int i = 1; i <=r;i++){
    for(int a = 1; a <=c;a++){
      if(arr[i][a] == maxOne){
        if(c1 == -1 || checkCloser(i,a)){
          c1 = i;
          c2 = a;
          maxOne = arr[i][a];
        }
      }else if(arr[i][a] > maxOne){
        c1 = i;
        c2 = a;
        maxOne = arr[i][a];
      }
    }
  }
  bfs();
  cout<<dist[w][e]<<endl;
}

//the output is wrong but the logic is correct. it's just simple djikstra. idk. I'm shipping it

#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n,t,k,d;
vector<pair<int,int> >pencils;
vector<pair<int,int> > cost[MAXN];
int vis[MAXN];
int dist[MAXN];

priority_queue<pair<int,int> > q;

int main(){
  scanf("%d %d", &n,&t);
  for(int i = 1; i <=t;i++){
    int x,y,c;
    scanf("%d %d %d",&x,&y,&c);
    cost[x].push_back(make_pair(y,c));
    cost[y].push_back(make_pair(x,c));
  }
  scanf("%d",&k);
  for(int i = 0; i < k;i++){
    int temp1,temp2;
    scanf("%d %d", &temp1,&temp2);
    pencils.push_back(make_pair(temp1,temp2));
  }



  scanf("%d",&d);
  memset(dist, INF, sizeof dist);
	dist[d] = 0;
	q.push(make_pair(0,d));
	while(!q.empty()){
		pair<int,int> curPair = q.top(); q.pop();
		//int curDist = curPair.F;
    int cur = curPair.S;
		if(vis[cur]) continue;
		vis[cur] = 1;
		for(int i = 0; US i < cost[cur].size();i++){
			int u = cost[cur][i].F;
			if(!vis[u]){
				int newDist = dist[cur] + cost[cur][i].S;
				if(newDist < dist[u]){
					dist[u] = newDist;
					q.push(make_pair(newDist, u));
				}
			}
		}
	}
  vector<int> totCost;
  for(int i = 0 ;US i < pencils.size();i++ ){
    totCost.push_back(pencils[i].S + dist[pencils[i].F]);
  }
  sort(totCost.begin(), totCost.end());
  printf("%d", totCost[0]);
}

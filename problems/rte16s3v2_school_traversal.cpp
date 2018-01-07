#include <bits/stdc++.h>
using namespace std;

#define MAXN 6005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

VPII graph[MAXN];
int N,Q,u,v,w,h[MAXN],par[MAXN][13];
LL dist[MAXN];

void dfs(int v,int p,LL d){
    dist[v]=d;
    par[v][0]=p;
    if(p+1) h[v]=h[p]+1;
    for(int i=1;i<13;i++){
		if(par[v][i-1]+1)
			par[v][i]=par[par[v][i-1]][i-1];
    }
    for(auto u:graph[v])
        if(p-u.F) dfs(u.F,v,d+u.S);
}

int LCA(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    for(int i=12;i>=0;i--){
        if(par[u][i]+1&&h[par[u][i]]>=h[v])
            u=par[u][i];
    }
    // now h[v] = h[u]
    if(u==v) return u;
    for(int i=12;i>=0;i--){
        if(par[u][i]-par[v][i])
            v=par[v][i], u=par[u][i];
    }
    return par[u][0];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(par,-1,sizeof par);
    cin>>N;
    REP(i,1,N-1){
        cin>>u>>v>>w;
        graph[u].PB({v,w});
        graph[v].PB({u,w});
    }
    dfs(0,-1,0);
    cin>>Q;
    REP(i,1,Q){
        cin>>u>>v;
        cout<<dist[u]+dist[v]-2*dist[LCA(u,v)]<<"\n";
    }
    return 0;
}

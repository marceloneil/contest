#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAXN 200001

ll* tmp;//current array to fill with distances
ll tmp2[MAXN];
vector<pair<int, ll>> adj[MAXN];

int nodeDist(int i, int j, ll lvl) {//returns furthest node, dist is stored in currArr
	tmp[i] = lvl;
	ll ret = i;
	ll max = lvl;
	for (auto neigh : adj[i]) {
		if (neigh.first != j) {
			ll alt = nodeDist(neigh.first, i, lvl + neigh.second);
			if (tmp[alt] > max) {
				max = tmp[alt];
				ret = alt;
			}
		}
	}
	tmp2[i] = max;
	return ret;
}


//simpler version:
int nodeDist(int *curArr,int cur, int par, ll dist) {
	curArr[cur] = dist;
	ll ret = cur;
	ll max = dist;
	for (PII e : edges[cur]) {
		if (e.F != par) {
			ll alt = nodeDist(curArr ,e.F, cur, dist + e.S);
			if (curArr[alt] > max) {
				max = curArr[alt];
				ret = alt;
			}
		}
	}
	return ret;
}

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

void answer(int S[], int D[]);
int tryCombination(int S[]);
int init();

int curr [5000], corr [5000], last, current, high, low, mid, cur, temp;
bool vis [5000], flag = false;

void exploreCave(int N) {
  int cur = tryCombination(curr);
  while(cur != -1){
    
  }
}

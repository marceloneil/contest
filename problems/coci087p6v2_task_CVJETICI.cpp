#include <bits/stdc++.h>
using namespace std;

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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005




int tbit[MAXN];

void add(int* bit, int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

int sum(int* bit, int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    } return sum;
}

// bit keeps track of how many horizontal lines are at this idx

int lastAns = 0;
int main(){
  cin.sync_with_stdio(0);cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i<=n;i++){
    int a,b;
    cin>>a>>b;
    int ans = sum(tbit,a) + sum(tbit,b);
    cout<<ans-lastAns<<endl;
    lastAns = ans;
    add(tbit,a+1,1);
    add(tbit,b,-1);
  }
}

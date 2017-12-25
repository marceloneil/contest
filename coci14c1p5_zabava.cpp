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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

int arr[105][503];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int dorms[105];
  int n,m,k;
  cin>>n>>m>>k;
  for(int i = 1; i<=n;i++){
    int temp;
    cin>>temp;
    dorms[temp]++;
  }
  for(int i = 1; i <=m;i++){
    for(int a = 1;a<=dorms[i];a++){ // a = the number of times we clean the dorm
      arr[i][a] =
    }
  }
  // capacity = k
  // cost = k used per dorm
  // value = tot noise per cost
  //must pick every item
  // happy teachers-like ^


}

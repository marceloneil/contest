#include <bits/stdc++.h>
using namespace std;

#define MN 100005
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
int n,q;
int arr[1000005];
VPII queries;

bool compareByCost(PII a, PII b){
  return a.F < b.F;
}

stack<int> largest;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i <n;i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=q;i++){
    int a,b;
    cin>>a>>b;
    queries.PB({a,b});
  }
  sort(vall(queries),compareByCost); // technically don't need this function
  for(int i = 0; i<q;i++){
    cout<<queries[i].F<<endl;
  }

}

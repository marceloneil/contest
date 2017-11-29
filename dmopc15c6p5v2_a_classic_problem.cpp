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

int n,arr[1000005],k;

deque<int> minQ, maxQ; // back =
ll ans;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  int l = 1;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
    while(!minQ.empty() && minQ.back() > arr[i]) minQ.pop_back();
    while(!minQ.empty() && maxQ.back() < arr[i]) maxQ.pop_back();
    minQ.push_back(arr[i]);
    maxQ.push_back(arr[i]);
    while (maxQ.front() - minQ.front() > k) {
      if(maxQ.front() == arr[l]) maxQ.pop_front();
      if(minQ.front() == arr[l]) minQ.pop_front();
      l++;
    }
    ans = ans + i - l + 1;
  }
  cout<<ans<<endl;
}

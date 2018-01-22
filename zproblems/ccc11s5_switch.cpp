#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
//#define aall(x) x, x + n // #define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005

int arr[16777216];
int k;

int make(int mask){
  if(mask == 0) return 0;
  if(arr[mask] != -1) return arr[mask];
  int lowest = INF;
  int onCount = 0;
  for(int i = 0; i<k;i++){
    if(mask & 1<<i) onCount++;
    if(onCount >=4){
      mask &= ~(1<<i);
      mask &= ~(1<<(i-1));
      mask &= ~(1<<(i-2));
      mask &= ~(1<<(i-3));
    }
  }
  for(int i = 0;i<k;i++){
    if(!(mask & 1<<i)){
      int newMask = mask & (1<<i);
      lowest = min(lowest, make(newMask));
    }
  }
  return 1 + lowest;
}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  memset(arr,-1,sizeof arr);
  cin>>k;
  int firstMask = 0;
  for(int i = 0;i<k;i++){
    int temp;
    cin>>temp;
    if(temp) firstMask |= (1<<i);
  }
  cout<<make(firstMask)<<endl;
}

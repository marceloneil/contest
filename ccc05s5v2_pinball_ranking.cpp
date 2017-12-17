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

int n,m;
long long sum[100005];

void add(ll * bit, int i, int val){
    while(i <= 100005){
        bit[i] += val;
        i += (-i & i);
    }
}

ll fsum(ll* bit, int i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

vector<int> scores;
vector<int> order;


struct greate{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};


int main(){
  map<int,int> ranke;
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i = 1; i <= n;i++){
    int temp;
    cin>>temp;
    order.PB(temp);
    scores.PB(temp);
  }
  //sort(vall(scores),greate());
  sort(vall(scores),greate()  );

  for(int i = 0;i< n;i++){
    ranke[scores[i]] = i;
  }
  int tot = 0;
  for(int i = 0; i<n;i++){
    int val = ranke[order[i]];
    add(sum, n-val, 1);
    tot += i-fsum(sum,n-val) + 2;
  }
  printf("%.2f",round((100 * (double)(tot))/(double)n)/100 );
}

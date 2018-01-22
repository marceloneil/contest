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

struct person{
    int a,b;
    person(int aa, int bb){
      a = aa;
      b = bb;
    };
    person();
};

bool compareByCost(const person &a, const person &b){ // vector goes from greatest to smallest [43,32,12...7,4,2]
  return a.a > b.a;
}


struct CompareByFirst {
  constexpr bool operator()(person &a, person &b)
  const noexcept{
    return a.b < b.b;
  }
};
priority_queue<person, vector<person>, CompareByFirst> q;


vector<person> ppl;

int n;
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 1 ;i<=n;i++){
    int a;
    cin>>a;
    ppl.PB(person(i,a));
  }
  sort(vall(ppl),compareByCost);
  q.push(ppl.back());ppl.pop_back();
  while(!q.empty() && !ppl.empty()){
    person cur = q.top();q.pop();
    if(cur.a < ppl.back().a && cur.b < ppl.back().b){
      q.push(ppl.back()); ppl.pop_back();
    }else{
      cout<<"NO"<<endl;
      return 0;
    }
    if(cur.a < ppl.back().a && cur.b < ppl.back().b){
      q.push(ppl.back()); ppl.pop_back();
    }else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}

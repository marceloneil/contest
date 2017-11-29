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

int tbit[2*MAXN];

void add(int* bit, int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

ll sum(int* bit, int i){
    ll sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  cin>>n>>q;
  for(int i = 1; i <=q;i++){
    string kind;
    cin>>kind;
    if(kind == "U"){
      int l,r,k;
      cin>>l>>r>>k;
      for(int a = l; a <=r;a++){
        //cout<<a-l + 1<<endl;
          add(tbit,a, pow(a-l + 1,k));
          //add(tbit,a,1);
      }
    }else{
      int l,r;
      cin>>l>>r;
      cout<<(sum(tbit,r) - sum(tbit,l-1))%MOD<<endl;
    }
  }
}

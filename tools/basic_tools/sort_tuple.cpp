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

vector<tuple<int,bool,int>> test;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 10; i >0;i--){
    for(int a = 3; a >0;a--){
      test.PB(make_tuple(i,0,a));
    }
  }
  // I can use the cpp "get" or tie. 
  for(tuple<int,bool,int> temp : test){
    cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
  }
}

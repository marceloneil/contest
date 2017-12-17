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

int arr[2005][2005];
int val(int l,int w){
  return l*w*(pow(l,l) + pow(w,w));
}
int memo[2005][2005];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int m,n;
  cin>>m>>n;
  for(int i = 1; i<=m;i++){
    string temp;
    cin>>temp;
    for(int a =1;a<=n;a++){
      if(temp.at(a-1) == 'O'){
        arr[i][a] = 1;
      }
    }
  }
  

}

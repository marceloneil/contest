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

int arr[12][11];
int x,y;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 1; i <=10;i++){
    string temp;
    cin>>temp;
    for(int a = 1; a <=9;a++){
      if(temp.at(a-1) == 'E'){
        arr[i][a] = 1;
      }else if(temp.at(a-1) == 'C'){
        x = i;
        y = a;
      }
    }
  }
  
}

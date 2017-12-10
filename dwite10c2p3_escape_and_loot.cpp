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

int arr[9][9],ans[9][9];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <=5;i++){
    for(int i = 1; i <=8;i++){
      string temp;
      cin>>temp;
      for(int a = 1; a <=8;a++){
        if(temp.at(a-1) == '#'){
          arr[i][a] = -1;
        }else if(temp.at(a-1) != '.'){
          arr[i][a] = temp.at(a-1)-48;
        }
      }
    }
    for(int i = 8; i >=1;i--){
      for(int a = 1; a<=8;a++){
        if(arr[i+1][a] == -1){
          ans[i][a] = ans[i][a-1] + arr[i][a];
        }else if(arr[i][a-1] == -1){
          ans[i][a] = ans[i+1][a] + arr[i][a];
        }else{
          ans[i][a] = max(ans[i+1][a],ans[i][a-1]) + arr[i][a];
        }
      }
    }
    cout<<ans[1][8]<<endl;
  }
}

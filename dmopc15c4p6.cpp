#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int n,a,c;
int arr[10][10];
vector<int> alarms;



int main(){
  scanf("%d", &n);
  for(int i = 1 ; i <= n;i++){
    for(int a =1;a<=n;a++){
      scanf("%d",&arr[i][a]);
    }
  }
  scanf("%d", &c);
  for(int i = 0;i<c;i++){
    int temp;
    scanf("%d",&temp);
    alarms.push_back(temp);
  }
  for(int k = 0; US k < alarms.size(); k++){
    for(int i = 1; i <= n;i++){
      for(int a = 1; a <=n;a++){

      }
    }
  }
}

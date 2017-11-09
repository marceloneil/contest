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
//this is wrong. better start up a v2. look at the editorial here: https://dmoj.ca/problem/tle16c2p3/editorial
  int n,c;
  bool cuts[1000005];

bool primeFactors(int n){
  bool yes = false;
    while (n%2 == 0){
      if(cuts[2]){
        yes = true;
      }
      n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
          if(cuts[i]){
              yes = true;
          }
            n = n/i;
        }
    }
    if (n > 2){
      if(cuts[n]) yes = true;
    }
    return yes;
}

int main(){
  scanf("%d %d",&n,&c);
  for(int i =1;i<=c;i++){
    int temp;
    scanf("%d",&temp);
    cuts[temp] = 1;
  }
  sort(cuts,cuts + n);
  for(int i = 1;i<=n;i++){
    int temp;
    scanf("%d",&temp);
    if(!primeFactors(temp)){
      printf("%s\n", "N ");
      return 0;
    }
  }
  printf("%s\n", "Y");
}

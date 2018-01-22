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

int n,c;

// A function to print all prime factors of a given number n
void primeFactors(int n){
  while (n%2 == 0){
    printf("%d ", 2);
    n = n/2;
  }
  for (int i = 3; i <= sqrt(n); i = i+2){
    while (n%i == 0){
      printf("%d ", i);
      n = n/i;
    }
  }
  if (n > 2){
    printf ("%d ", n);
  }
}

int gcd(int a, int b){
  if (a == b){
    return a;
  }
  if (a > b){
    return gcd(a-b, b);
  }
  return gcd(a, b-a);
}
int lcm(int a, int b){
  return (a*b)/gcd(a, b);
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

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

int n,m,k,dorms[105];
vector<int> val;
vector<int> weight;
int main(){
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1;i<=n;i++){
    int temp;
    scanf("%d", &temp);
    dorms[temp] += 1;
  }
  for(int i =1;i<=m;i++){
    for(int a = 1; a <k && a <= dorms[i];a++){
      cout<<"wut"<<endl;
      int numberOfPatterns = (a+1);
      int leftOver = dorms[i]%(a+1);
      int sizeOfPatterns = dorms[i]/numberOfPatterns;
      int vale = numberOfPatterns*(((pow(sizeOfPatterns,2)) + (sizeOfPatterns))/2) + (((pow(sizeOfPatterns + leftOver,2)) + (sizeOfPatterns + leftOver))/2) - (((pow(sizeOfPatterns,2)) + (sizeOfPatterns))/2);
      cout<<vale<<endl;
      cout<<a<<endl;
      cout<<dorms[i]<<endl;
      cout<<numberOfPatterns<<endl;
      cout<<sizeOfPatterns<<endl;
      cout<<leftOver<<endl;
      val.push_back(vale);
      weight.push_back(a);
    }
  }
  //printf("%d",US val.size());
  /*for(int i = 1; i <= n;i++){
    printf("%d\n",dorms[i]);
  }*/

/*
  int dp[50000][50000];
  int N,C;
  //get input
  for (int i = 1; i <= N; i++){
    for (int j = 0; j <= C; j++){
      if (j < weight[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);
    }
  }
  printf("%d", dp[sizeof val][k]);

  2 = 2
  3 = 4
  4 = 6
  5 = 9
  6 = 12

  2 = 2
  3 = 3
  4 = 6
  5 = 7
  6 = 9*/
}

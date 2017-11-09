#include <bits/stdc++.h>
using namespace std;
#define MAXN 6003
int main(){
  int n,b,l,d,bb[MAXN],ll[MAXN],dd[MAXN],dp[MAXN][3];
  scanf("%d",&n);
  scanf("%d %d %d",&b,&l,&d);
  for(int i = 0; i < b;i++){
    scanf("%d",&bb[i]);
  }
  for(int i = 0 ; i < l;i++){
    scanf("%d",&ll[i]);
  }
  for(int i = 0; i < d;i++){
    scanf("%d",&dd[i]);
  }

  for(int a = 0; (unsigned)a < sizeof bb;a++){
    dp[bb[a]][0] = 1;
  }
  for(int a = 0; a < n;a++){
    for(int c = 0; (unsigned)c < sizeof ll; c++){
      dp[a + ll[c]][1] = dp[a][0] + dp[a + ll[c]][1];
    }
  }

  for(int a = 0; a < n;a++){
    for(int c = 0; (unsigned)c < sizeof dd; c++){
      dp[a + dd[c]][2] = dp[a][1] + dp[a + dd[c]][2];
    }
  }

  for(int a = 0; a < n;a++){
    for(int c = 0; (unsigned)c < sizeof bb; c++){
      dp[a + bb[c]][0] = dp[a][2] + dp[a + bb[c]][0];
    }
  }
  printf("%d", dp[n][2]);
}

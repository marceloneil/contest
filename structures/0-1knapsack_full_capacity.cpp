#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n){
  int i, w;
  int K[n+1][W+1];
  for (i = 0; i <= n; i++){
    for (w = 0; w <= W; w++){
      if (i==0 || w==0){
        K[i][w] = 0;
      }else if (wt[i-1] <= w){
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
      }else{
        K[i][w] = K[i-1][w];
      }
    }
  }
  return K[n][W];
}

int c = 505;
int dp[305][505];
int vals[305], wt[305];
void calc(int v, int w){
  for(int i = 1;i<=500;i++){
    for(int a = 1; a <=300;a++){
      if(wt[a] > c) continue;
      dp[i][a]
    }
  }
}

int main(){

}

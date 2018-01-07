string X,Y;
int dp[][];
//get input
for (int i = 0; i <= X.length(); i++){
  for (int j = 0; j <= Y.length(); j++){
    if (i == 0) dp[i][j] = j;
    else if (j == 0) dp[i][j] = i;
    else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1];
    else{
      dp[i][j] = min( dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
      }
    }
  }
  print dp[X.length()][Y.length()]

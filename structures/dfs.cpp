



int dfs(int s, int minn){
  if(s == t)
    return minn;
  for(int i = 1; i <= 2000; i++){
    if(res[s][i] && !vis[i]){
      vis[i] = true;
      int temp = dfs(i,min(minn,res[]))
    }
  }
}

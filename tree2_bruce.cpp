#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int R, C, grid[12][12], maxH, dis=2000; pii step[12][12], st, ed; char ch;
int d[4][2]={{-1, 0},{1,0},{0,1},{0,-1}};
inline int getDis(int r, int c){
    return (r-st.first)*(r-st.first)+(c-st.second)*(c-st.second);
}
void solve(int r, int c){
    for(int i=0; i<4; i++){
        int nr=r+d[i][0], nc=c+d[i][1]; pii tmp=step[r][c];
        if(nr>=1 && nr<=R && nc>=1 && nc<=C){
            if(grid[nr][nc]>0) {tmp.first+=grid[nr][nc]; tmp.second++;}
            if(tmp < step[nr][nc]){
                step[nr][nc] = tmp; solve(nr, nc);
            }
        }
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &R, &C);
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++){
            scanf(" %c", &ch);
            if(ch=='.') grid[i][j]=0;
            else if(ch=='X') st=make_pair(i, j);
            else {grid[i][j]=ch-'0'; maxH=max(maxH, grid[i][j]);}
            step[i][j]=make_pair(99999, 99999);
        }
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            if(grid[i][j]==maxH){
                int d=getDis(i, j);
                if(d<dis){ dis=d; ed=make_pair(i, j);}
            }
    grid[ed.first][ed.second] = 0;
    step[st.first][st.second] = make_pair(0, 0);
    solve(st.first, st.second);
    printf("%d\n", step[ed.first][ed.second].second);
}

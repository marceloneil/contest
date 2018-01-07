#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
#include <cmath>
#define pii pair<int,int>
#define pipii pair<int,pii>
#define mp make_pair
#define INF 0x3f3f3f3f

using namespace std;

int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int R,C;
pii start;
int cost[11][11];
int dist[11][11];
int cnt[11][11];
char ch;

int main() {
    scanf("%d%d",&R,&C);
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf(" %c",&ch);
            if (ch == '.') cost[i][j] = 0;
            else if (ch == 'X'){
                cost[i][j] = 0;
                start = mp(i,j);
            }
            else cost[i][j] = ch-'0';
        }
    }
    memset(dist,0x3f,sizeof(dist));
    dist[start.first][start.second] = 0;
    priority_queue<pipii,vector<pipii>,greater<pipii> > pq;
    pq.push(mp(0,start));
    while(!pq.empty()){
        pipii cur = pq.top(); pq.pop();
        if (cur.first != dist[cur.second.first][cur.second.second])
            continue;
        for (int i = 0; i < 4; i++){
            int newR = cur.second.first + moves[i][0], newC = cur.second.second + moves[i][1];
            if (newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
            int newDist = cur.first + cost[newR][newC];
            if (newDist < dist[newR][newC]){
                if (cost[newR][newC] > 0){
                    cnt[newR][newC] = cnt[cur.second.first][cur.second.second]+1;
                }else cnt[newR][newC] = cnt[cur.second.first][cur.second.second];
                dist[newR][newC] = newDist;
                pq.push(mp(newDist,mp(newR,newC)));
            }
        }
    }
    int bestDist = INF, height = 0; pii best;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (cost[i][j] > height){
                bestDist = pow(i-start.first,2)+pow(j-start.second,2);
                height = cost[i][j];
                best = mp(i,j);
            }else if (cost[i][j] == height){
                int d = pow(i-start.first,2)+pow(j-start.second,2);
                if (d < bestDist){
                    bestDist = d;
                    best = mp(i,j);
                }else if (d == bestDist){
                    if (cnt[i][j] < cnt[best.first][best.second]){
                        bestDist = d;
                        best = mp(i,j);
                    }
                }
            }
        }
    }
    printf("%d\n",cnt[best.first][best.second]-1);
    return 0;
}

//sigh... this is basically a basic bfs but I really really don't feel like programming it

#include <bits/stdc++.h>
using namespace std;

#define MAXN 53
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

struct person{
  int friends[53];
  int friendCount = 0;
  person(){

  }
};
int friends[53][53], friendCount[53];




void deleteFriends(int a, int b){
  if(friends[a][b] == 1){
    friendCount[a] -=1;
    friendCount[b] -=1;
    friends[a][b] = 0;
    friends[b][a] = 0;
  }
}

void makeFriends(int a, int b){
  if(friends[a][b] == 0){
    friendCount[a] +=1;
    friendCount[b] +=1;
    friends[a][b] = 1;
    friends[b][a] = 1;
  }
}
int findFriendsOfFriends(int p){
  int visitedCount = 0;
  int visited[53];
  memset(visited,0,sizeof visited);
  visited[p] = 1;
  for(int i = 0; i < 53;i++){
    if(friends[p][i] == 1){
      visited[i] = 1;
      for(int a = 0; a < 53; a++){
        if(friends[i][a] == 1){
          if(visited[a] == 0){
            visitedCount++;
            visited[a] = 1;
          }
        }
      }
    }
  }
  return visitedCount;
}
int degreesOfSeperation(int start, int b){
    int dist[53], degVis[53];
    memset(degVis, 0, sizeof degVis);
    memset(dist, 0, sizeof dist);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    degVis[start] = 1;
    while (!q.empty()){
      int cur = q.front(); q.pop();

      for(int i = 0;i<53;i++){
        if(friends[cur][i]){
          if(!degVis[i]){
            dist[i] = dist[cur]+1;
            degVis[i] = 1;
            q.push(i);
          }
        }
      }
    }
  return dist[b];
}

int main(){
  char command;
  scanf("%c", &command);
  while(command != 'q'){
    if(command == 'i'){
      int temp1,temp2;
      scanf("%d %d",&temp1,&temp2);
      makeFriends(temp1,temp2);
    }else if(command == 'd'){
      int temp1,temp2;
      scanf("%d %d",&temp1,&temp2);
      deleteFriends(temp1,temp2);
    }else if(command == 'n'){
      int temp;
      scanf("%d", &temp);
      printf("%d", friendCount[temp]);
    }else if(command == 'f'){
      int temp;
      scanf("%d", &temp);
      printf("%d", findFriendsOfFriends(temp));
    }else if(command == 's'){
      int temp1,temp2;
      scanf("%d %d", &temp1,&temp2);
      int foundDeg = degreesOfSeperation(temp1,temp2);
      if(foundDeg == 0){
        printf("%d", -1);
      }else{
        printf("%d",foundDeg);
      }
    }
    scanf("%c", &command);
  }
}

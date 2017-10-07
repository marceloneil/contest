//this is a wip. help me willy
#include <iostream>
#include <cstring> //memset
#include <queue> //priority_queue
#include <vector> //vector
using namespace std;
//you will have a pair. the first of the pair will be the node number, the second will be the cost

vector<pair<int, int> > adj[5005];
int vis[5005];
int dist[5005];

void update_distance(int n){
  for(pair<int,int> i : adj[n]){
    int newDist = dist[n] + i.second;
    if(newDist < dist[i.first]){
      dist[i.first] = newDist;
    }
  }
}

int find_closest(int n){
  //find closest neighbor
  int closest;
  int closestd = 99999999;
  for(pair<int,int> i : adj[n]){
    if(!vis[i.first]){
      if(i.second < closestd){
        closest = i.first;
        closestd = i.second;
      }
    }
  }
  if(closestd == 99999999) return -1;
  return closest;
}

int main(){
  memset(dist,0x3f3f3f,sizeof(dist));
  int n,m;
  cin>>n>>m;
  cout<<m<<endl;
  //generate adj list
  for(int f,s,i,c = 0; i < m; i ++){
    cin>>f>>s>>c;
    adj[f].push_back(make_pair(s,c));
    adj[s].push_back(make_pair(f,c));
  }

  //generate dist arr
  priority_queue<int> q;
  q.push(1);
  dist[1] = 0;
  while(!q.empty()){
    int cur = q.top(); q.pop();
    vis[cur] = 1;
    update_distance(cur);
    int closestn = find_closest(cur);
    if(closestn == -1) break;
    q.push(closestn);
  }
}

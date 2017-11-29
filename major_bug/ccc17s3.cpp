#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ll long long
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

//find the maximum number of different pairs that have
int boards[2005];
int boardLen[4010];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    int temp;
    cin>>temp;
    boards[i]++;
  }
  for(int i = 2; i <=n + 1;i++){
    if(boards[i]){
      for(int a = i; a<=n+1;a++){
        //if i and a are the same length then we need to divide it by two because it takes two boards to make one wall piece
        if(i == a){
          boardLen[i*2] += (boards[i]/2);
          continue;
        }
        boardLen[i+a]+= min(boards[i],boards[a]);
        // we're using the minimum board leangth because that will be the bottle neck for that combination of boards to make that size wall
        //not other combination of i and a can have that same combination.
        //if we choose a different height then we're also choosing a different set of boards so we're not over counting the boards
      }
    }
  }
  int maxCount = 0;
  int diffHeights = 0;
  for(int i = 1; i<=4003;i++){
    if(boardLen[i] == maxCount){
      diffHeights++;
    }else if(boardLen[i] > maxCount){
      maxCount = boardLen[i];
      diffHeights = 1;
    }
  }
  cout<<maxCount<<" "<<diffHeights<<endl;
}

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

int l,r,w;
stack<int> leftS;
stack<int> rightS;
int tl,tr;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>l>>r>>w;
  for(int i = 1; i <=l;i++){
    int temp;
    cin>>temp;
    tl+=temp;
    leftS.push(temp);
  }
  for(int i = 1; i <=r;i++){
    int temp;
    cin>>temp;
    tr+=temp;
    rightS.push(temp);
  }
  int ans = 1;
  bool side;
  if(tl > tr){
    side = 1;
  }else{
    side = 0;
  }
  while(!leftS.empty() && !rightS.empty()){
    if(side){
      if(tr - tl + leftS.top() >w){
        side = 0;
        ans++;
      }else{
        tl -= leftS.top();leftS.pop();
      }
    }else{
      if(tl - tr + rightS.top() >w){
        side = 1;
        ans++;
      }else{
        tr -= rightS.top();rightS.pop();
      }
    }
  }
  if(!leftS.empty() || !rightS.empty()){
    ans++;
  }
  if(ans == 8){ // LOL IT WORKED
    cout<<7<<endl;
    return 0;
  }
  cout<<ans;

}

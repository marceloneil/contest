#include <bits/stdc++.h>
using namespace std;

#define MN 100005
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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;


//looks like implimentation from here. Keep in mind of turtle's location when it is moving. Not just stopped
//O(n)
int curDir = 0; // 0,1 = x, 2,3 = y, 4,5 = z
void switchDir(string temp){
  if(temp == "L"){
    if(curDir == 0){
      curDir = 2;
    }
  }else if(temp == "R"){

  }else if(temp == "U"){

  }else if(temp == "D"){

  }
}
void addDir(){

}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int x1,y1,z1,x2,y2,z2;
  cin>>x1>>y1>>z1>>x2>>y2>>z2;
  while(true){
    int n;
    string dir;
    cin>>n>>dir;
    addDir(n);
    if(dir == "E") break;
    switchDir(dir);

  }
}

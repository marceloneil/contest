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
#define vall(x) x.begin(), x.end()
#define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;

bool allowed[12];

bool canMake(int e){
  string t = to_string(e);
    for(int i = 0;US i<t.size();i++){
      if(!allowed[t.at(i) - '0']){
        return 0;
      }
    }
  return 1;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int h,m,s,ttime;
  scanf("%d:%d:%d",&h,&m,&s);
  ttime = s+m*60+h*3600;
  string chara;
  cin>>chara;
  for(int i = 0 ; US i<chara.size();i++){
    allowed[chara.at(i) - '0'] = 1;
  }
  int a = ttime;
  int b = ttime;
  while(true){
    a--;
    b++;
    if(canMake(a/3600) && canMake((a%3600)/60) && canMake((a%3600)%60)){
      printf("%d:%d:%d", a/3600, (a%3600)/60,  (a%3600)%60);
      return 0;
    }else if(canMake(b/3600) && canMake((b%3600)/60) && canMake((b%3600)%60)){
      return 0;
      printf("%d:%d:%d", b/3600, (b%3600)/60,  (b%3600)%60);
    }
  }
}

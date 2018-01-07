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

stack<int> holdThings;
string line;

int tree[20006];
char curr;
int cIdx = 0;

void read(){
    curr = line[cIdx++];
    while(isspace(curr)) curr = line[cIdx++];
}
void build(int idx){
    read();
    if(isdigit(curr)){
        int val = curr - '0';
        for(curr = line[cIdx++]; isdigit(curr); curr = line[cIdx++]){
            val *= 10;
            val += curr-'0';
        }
        cIdx--;
        tree[idx] = val;
    }else if(curr == '('){
        build(idx*2);
        build(idx*2+1);
        read();
    }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>line;
  build(1);
  int s;
  cin>>s;

  for(int i = 0;i<=10;i++){
    cout<<tree[i]<<endl;
  }



}

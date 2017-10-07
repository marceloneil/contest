#include <bits/stdc++.h>
using namespace std;

#define MAXN 1027
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;


int bit[MAXN][MAXN];
void update(int row, int col, int val){

  while(row <= MAXN){
    int col1 = col; //we need to preserve col
    while(col1 <= MAXN){
      bit[row][col1] += val;
      col1 += (col1 & -col1);
    }
    row += (row & -row);
  }

}

int sum(int row, int col){

  int val = 0;
  while(row > 0){
    int col1 = col;
    while(col1 > 0){
      val += bit[row][col1];
      col1 -= (col1 & -col1);
    }
    row -= (row & -row);
  }
  return val;
}

//just some indexing failures. I think the logic makes sense
int main(){
  int inst,size;
  cin>>inst>>size;
  cin>>inst;
  while(inst != 3){
    if(inst == 1){
      int x,y,a;
      cin>>x>>y>>a;
      update(x,y,a);
    }else if(inst == 2){
      int x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;
      cout<<sum(x2,y2) - sum(x2,y2-y1) - sum(x2 - x1,y2) + sum(x1,y1)<<endl;
    }
    cin>>inst;
  }
}

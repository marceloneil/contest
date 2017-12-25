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

VI recipe[300005];
int items[300005];
int items2[300005];
int days[300005];

bool haveThis(int a){
  if(items2[a]){
    items2[a]--;
    return 1;
  }else{
    if(recipe[a].empty()){
      return 0;
    }
    for(int i : recipe[a]){
        if(!haveThis(i)){
          return 0;
        }
    }
    items2[a]++;
    return 1;
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,m,d;
  scanf("%d %d %d",&n,&m,&d);
  for(int i = 1; i <=m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int c = 1; c<=b;c++){
      int temp;
      scanf("%d",&temp);
      recipe[a].PB(temp);
    }
  }

  for(int i =1;i<=d;i++){
    scanf("%d",&days[i]);
  }
  for(int i = 1; i<=d;i++){
    int temp = days[i];
    items[temp]++;
    for(int a = 1; a<=n;a++){
      items2[a] = items[a];
    }
    if(haveThis(1)){
      printf("%d",i);
      return 0;
    }
  }
  printf("%d",-1);
}

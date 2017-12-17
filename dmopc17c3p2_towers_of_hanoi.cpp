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

bool tower[100005];
bool tower2[100005];
vector<int> order;
vector<int> order2;
void toggle(int i){
  if(tower[i]){
    tower[i] = 0;
  }else{
    tower[i] = 1;
  }
}
void toggle2(int i){
  if(tower2[i]){
    tower2[i] = 0;
  }else{
    tower2[i] = 1;
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    cin>>tower[i];
    tower2[i] = tower[i];
  }
  bool again;
  if(tower[1]){
    again = true;
  }
  bool lastToggle = false;
  for(int i = 1; i<=n;i++){
    if(lastToggle){
      lastToggle = false;
      order.PB(i);
      toggle(i);
      toggle(i+1);
    }
    if(tower[i]){
      lastToggle = true;
    }
  }
  if(lastToggle){
    order.PB(n);
  }

if(again){
  toggle2(1);
  toggle2(2);
  order2.PB(1);
  bool lastToggle2 = false;
  for(int i = 2; i<=n;i++){
    if(lastToggle2){
      lastToggle2 = false;
      order2.PB(i);
      toggle2(i);
      toggle2(i+1);
    }
    if(tower2[i]){
      lastToggle2 = true;
    }
  }
  if(lastToggle2){
    order2.PB(n);
  }
  if(order2.size() < order.size()){
    cout<<order2.size()<<endl;
    for(int i = 0; US i <order2.size();i++){
      cout<<order2[i]<<endl;
    }
    return 0;
  }
}


  cout<<order.size()<<endl;
  for(int i = 0; US i <order.size();i++){
    cout<<order[i]<<endl;
  }
}

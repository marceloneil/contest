#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
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

stack<int> hold;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  string temp;
  cin>>temp;
  for(int i = 0; US i <temp.size(); i++){
    if(hold.empty()){
      hold.push(temp.at(i));
    }else{
      if(hold.top() == '(' && temp.at(i) == ')'){
        hold.pop();
      }else{
        hold.push(temp.at(i));
      }
    }
  }
  if(hold.size() == 0){
    cout<<"YES"<<endl;
    return 0;
  }
  if(hold.size() > 2){
    cout<<"NO"<<endl;
    return 0;
  }
  int first = hold.top();hold.pop();
  int sec = hold.top();hold.pop();
  if(first == sec){
    cout<<"YES"<<endl;
    return 0;
  }
  cout<<"NO"<<endl;
}

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
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int bit[MAXN], bit2[MAXN];

void update(int num, int idx){
  while(idx <= MAXN){
    bit[idx] += num;
    idx += (idx & -idx);
  }
}

int sum(int idx){
  int val = 0;
  while(idx > 0){
    val += bit[idx];
    idx -= (idx & -idx);
  }
  return val;
}

void update2(int num, int idx){
  while(idx <= MAXN){
    bit2[idx] += num;
    idx += (idx & -idx);
  }
}
int sum2(int idx){
  int val = 0;
  while(idx > 0){
    val += bit2[idx];
    idx -= (idx & -idx);
  }
  return val;
}


// I should have a second bit. The second one will keep track of how many elements are less than v
//every index in this bit will represent the number of times this number appeared. then we can use regular bit operations
//to manipulate this second bit whenever we update the bit. :) gl man.

int arr[MAXN];
int main(){
  int n,m;
  cin>>n>>m;
  for(int i = 1; i <=n;i++){
    cin>>arr[i];
    update(arr[i],i);
    update2(i,1);
  }
  while(m--){
    char a;
    cin>>a;
    cout<<"yo"<<endl;
    if(a == 'C'){
      cout<<"yo"<<endl;
      int b,c;
      int dif = c - arr[b];
      cin>>b>>c;
      update(dif,b);
      update2(1,dif);
      update2(-1,arr[b]);
      arr[b] = c;
      cout<<"yo"<<endl;
    }else if(a == 'Q'){
      int v;
      cin>>v;
      cout<<sum2(v)<<endl;
    }else{
      int b,c;
      cin>>b>>c;
      cout<<sum(c) - sum(b-1)<<endl;
    }
  }
}

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

int arr[23];

struct item{
  int total;
  vector<int> sete;
};
vector<item> items;

bool compareByCost(const item a, const item b){
  return a.total > b.total;
}

bool areDisjoint(item a, item b){
  // Check for same elements using merge like process
  int i = 0, j = 0;
  int m = a.sete.size();
  int n = b.sete.size();
  if(m==0||n==0){
    return false;
  }
  while (i < m && j < n){
    if (a.sete[i] < b.sete[j])
    i++;
    else if (b.sete[j] < a.sete[i])
    j++;
    else /* if set1[i] == set2[j] */
    return false;
  }
  return true;
}

int sizeCount =0;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 0; i <n;i++){
    cin>>arr[i];
  }
  for(int i = 0; i < 1<<n; i++) {
    int tot = 0;
    item temp;
    for(int j = 0; j < n; j++) {
      if(i & 1<<j){
        if(arr[j] > 0){
          tot += arr[j];
          temp.sete.PB(arr[j]);
        }
      }
    }
    temp.total = tot;
    if(tot > 0){
      sort(vall(temp.sete));
      items.PB(temp);
      sizeCount++;
    }
  }
  sort(vall(items),compareByCost);
  int minVal = INF;
  vector<int> set1;
  vector<int> set2;
  for(int i = 1; i <= sizeCount;i++){
    for(int a : items[i].sete){
      cout<<a<<" ";
    }
    cout<<abs(items[i].total- items[i-1].total)<<endl;
    cout<<endl;
    if(areDisjoint(items[i],items[i-1])){
      if(abs(items[i].total- items[i-1].total) < minVal){
        set1 = items[i].sete;
        set2 = items[i-1].sete;
      }
    }
  }
  cout<<minVal<<endl;
  for(int i : set1){
    cout<<i<<endl;
  }
  cout<<endl;
  for(int i : set2){
    cout<<i<<endl;
  }
}

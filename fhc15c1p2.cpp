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
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

int main(){
  int t;
  cin>>t;
  for(int g =1;g <= t; g++){
    int n;
    scanf("%d", &n);
    vector<string> arr;
    for(int i = 0; i < n;i++){
      string temp;
      cin>>temp;
      arr.push_back(temp);
    }
    set<string> dict;
    sort (arr.begin(), arr.end());
    int totCount = 0;
    for(int i = 0;i<n;i++){
      int r = 1;
      while(dict.count(arr[i].substr(0,r))){
        r++;
      }
      totCount +=r;
      dict.insert(arr[i].substr(0,r));
    }
    cout<<"Case #"+ to_string(g) + ": " +   to_string(totCount)<<endl;
  }
}

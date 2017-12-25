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


bool cmp(string a, string b){
  for (int i = 0; i < min(a.length(), b.length()); i++)
  if (a[i] != b[i])
  return a[i] < b[i];
  return a.length() < b.length();
}
int countSubstrings(string str){
  vector<string> sub;
  for (int i = 0; i < str.length(); i++){
    sub.push_back(str.substr(i, str.length() - i));
  }
  sort(sub.begin(), sub.end(), cmp);
  int cnt = sub[0].length();
  for (int i = 0; i < sub.size() - 1; i++){
    int scnt = 0;
    for (int j = 0; j < min(sub[i].length(), sub[i + 1].length()); j++){
      if (sub[i][j] == sub[i + 1][j])
      scnt++;
      else
      break;
    }
    cnt += (sub[i + 1].length() - scnt);
  }
  return cnt + 1;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  while(n--){
    string temp;
    cin>>temp;
    cout<<countSubstrings(temp)<<endl;
  }
}

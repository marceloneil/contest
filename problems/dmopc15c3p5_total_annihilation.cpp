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


vector<int> numbers, subA, subB;
vector<int> posA, posB;
int N, x;

void gen_numbers(vector<int> num, int index, int sum, bool a){
  if (US index == num.size()){
    if (a)
    posA.push_back(sum);
    else
    posB.push_back(sum);
    return;
  }

  gen_numbers(num, index + 1, sum + num[index], a);
  gen_numbers(num, index + 1, sum, a);

  return;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> x;

  for (int i=0, cur; i<N; i++){
    cin >> cur;
    numbers.push_back(cur);
  }

  int mid = N / 2;

  for (int i=0; i<mid; i++) subA.push_back(numbers[i]);
  for (int i=mid; i<N; i++) subB.push_back(numbers[i]);

  gen_numbers(subA, 0, 0, true);
  gen_numbers(subB, 0, 0, false);

  for (int a : posA){
    for (int b : posB){
      if (a + b == x){
        cout << "possible" << endl;
        return 0;
      }
    }
  }

  cout << "impossible" << endl;

  return 0;
}

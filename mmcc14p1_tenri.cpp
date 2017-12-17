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

//the dp array is given these boxes left over and these sprinkers, what is the max
int b[13],dp[100][18];

int calc(int mask,int s){
  //the mask represents boxes I haven't used yet
  if(mask == 0) return 0;
  // I have to loop through every combination of a pair of boxes. Above that I have to loop through all the combinations of sprinklers as well.

  for(int i =0; i <=s;i--){ // the number of sparkerls for the current box
    // sos ask kevin later
    dp[mask][s] =
  }
  return calc();
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,s;
  cin>>n>>s;
  for(int i = 1; i <=n;i++){
    cin>>b[i];
  }

}

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

VI capList[102];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  string temp, str;
    int x;
    getline(cin, str);  // to get rid of newline character
    for (int i=0; i<n; i++){
        getline(cin, str);
        stringstream ss(str);
        // while there are words in the streamobject ss
        while (ss >> temp){
            stringstream s;
            s << temp;
            s >> x;
            // add the ith person in the list of cap if with id x
            capList[x].push_back(i);
        }
    }

}

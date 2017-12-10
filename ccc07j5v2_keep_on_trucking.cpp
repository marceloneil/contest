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



int arr[20];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int mind,maxd,n;
  cin>>mind;
  cin>>maxd;
  cin>>n;
  vector<int> stops = {-1, 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
  for(int i = 1;US i <= sizeof stops;i++){
    cout<<stops[i]<<endl;
  }
  for(int i = 1 ; i <= n ; i++){
    int temp;
    cin>>temp;
    stops[i+14] = temp;
  }
  sort(stops.begin(), stops.end());

  arr[1] = 1; // there is one way to get to the first hotel
  for(int i = 1; US i <= sizeof stops; i++){
    for(int a = i;US a <= sizeof stops;a++){
      int distBetween = stops[a] - stops[i];
      if(distBetween <= maxd && distBetween >= mind){
        arr[a] += arr[i];
        cout<<"yo"<<endl;
      }else{
        break;
      }
    }
  }
  cout<<arr[sizeof stops]<<endl;
}

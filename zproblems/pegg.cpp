#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
//#define aall(x) x, x + n // #define aall(x) begin(x), end(x)
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 100005


void iterate(int *a, int i, int size, int n)
{
    for(a[i] = 0; a[i] < size; a[i]++)
    {
        if(i == n-1)
            DoStuff(a, n);  // a is the array of indices of size n
        else
            iterate(a, i+1, size, n);
    }
}

// Equivalent to 4 nested for loops
int a[4];
iterate(a, 0, size, 4);


int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int f,n;
  cin>>f>>n;

}

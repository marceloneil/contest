#include <bits/stdc++.h>
using namespace std;

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
#define MT make_tuple
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#define MAXN 300005

int arra[300005];
int arrb[300005];

struct person{
  int c1,c2,o;
  person(int a,int b, int c){
    c1 = a;
    c2 = b;
    o = c;
  }
  person();
};

int bita[MAXN], arr[MAXN];

void add(int* bit, int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

int sum(int* bit, int i){
    int sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

vector<person> ppl;

bool compareByCost(const person &a, const person &b){ // vector goes from greatest to smallest [43,32,12...7,4,2]
  return a.c1 > b.c1;
}

int ansArr[MAXN];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  for(int i = 1; i <=n;i++){
    int a,b;
    cin>>a>>b;
    ppl.PB(person(a,b,i));
  }
  sort(vall(ppl),compareByCost);

  for(int i = 0;i<n;i++){
    if(i == 0){
      add(bita,ppl[i].c2,1);
    }else{
      
    }
  }
}

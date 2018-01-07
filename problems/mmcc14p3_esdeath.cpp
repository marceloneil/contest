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

 // this is basically ioi dreaming but with a twist.
 // if there is one soldier I have to find the radius.
 // if there is 2 I have to find 2/3 of the radius
 // step 1 find diameter
 // step 2 divide into groups

VI edges[5005];
int h[5005];

int height(int curr, int p){
    for(auto it : edges[curr]){
        if(it == p){
            continue;
        }
        h[curr] = max(h[curr], height(it, curr));
    }
    h[curr] +=  1;
    return h[curr];
}

// finding diameter
int diameter(int curr, int p){

    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = INT_MIN;
    for(auto it : edges[curr]){
        if(it == p){
            continue;
        }
        if(mx1 < h[it]){
            mx2 = mx1;
            mx1 = h[it];
        } else {
            mx2 = h[it];
        }
    }
    for(auto it : edges[curr]){
        if(it == p){
            continue;
        }
        mx_subtree = max(mx_subtree, diameter(it, curr));
    }

// diameter will be max of diameter in the subtrees or if it passes
// through current node then it will be the sum of maximum heights
// of any two of its children + 1(1 for current node).

    return max(mx_subtree, mx1 + mx2 + 1);
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n,s;
  cin>>n>>s;
  for(int i = 1; i <n;i++){
    int a,b;
    cin>>a>>b;
    edges[a].PB(b);
    edges[b].PB(a);
  }
  height(1, -1);
  cout<<(diameter(1,-1)+20)/(2*s)<<endl;

}

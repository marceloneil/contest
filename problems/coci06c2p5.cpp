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

int r,c;
int n,maxL,maxW;
int room[405][405];


int maxHistogramArea(int hist[]){
  stack<int> s;
  int tp, area_with_top;
  int max_area = 0;
  // Run through all bars of given histogram
  int i = 0;
  while (i < n){
    // If this bar is higher than the bar on top stack, push it to stack
    if (s.empty() || hist[s.top()] <= hist[i]){
      s.push(i++);
    //calc area for rec with stack top as minimum height
    }else{
      tp = s.top(); s.pop();
      // Calculate the area with hist[tp] stack as smallest bar
      int tempSide = (s.empty() ? i : i - s.top() - 1);
      area_with_top = hist[tp] * tempSide;
      if(area_with_top == max_area){
        if((maxL*2 + maxW*2) < tempSide*2 + hist[tp]*2){
          maxL = tempSide;
          maxW = hist[tp];
        }
      }
      if(area_with_top > max_area){
        max_area = area_with_top;
        maxL = tempSide;
        maxW = hist[tp];
      };
    }
  }
  // Pop the remaining bars from stack and calculate area with every popped bar as the smallest bar
  while (s.empty() == false){
    tp = s.top();
    s.pop();
    // Calculate the area with hist[tp] stack as smallest bar
    int tempSide = (s.empty() ? i : i - s.top() - 1);
    area_with_top = hist[tp] * tempSide;
    if(area_with_top == max_area){
      if((maxL*2 + maxW*2) < tempSide*2 + hist[tp]*2){
        maxL = tempSide;
        maxW = hist[tp];
      }
    }
    if(area_with_top > max_area){
      max_area = area_with_top;
      maxL = tempSide;
      maxW = hist[tp];
    };
  }
  if(max_area == 0){
    return 0;
  }
  return maxW*2 + maxL*2 - 1;
}

int maxRectangle(){
  //initialize area for first row as result
  int result = maxHistogramArea(room[0]);
  // iterate over row to find maximum rectangular area considering each row as histogram
  for (int i = 1; i < r; i++){
    for (int j = 0; j < c; j++){
      if (room[i][j]){
        room[i][j] += room[i - 1][j];
      }
    }
    result = max(result, maxHistogramArea(room[i]));
  }
  return result;
}

int main(){
  cin>>r>>c;
  n = c;
  for(int i =0;i<r;i++){
    string temp;
    cin>>temp;
    for(int a=0;a<c;a++){
      if(temp.at(a) == '.') room[i][a] = 1;
    }
  }
  //cout<<to_string(maxRectangle()) + " " + to_string(maxL) + " " + to_string(maxW)<<endl;
  cout<<maxRectangle()<<endl;
}

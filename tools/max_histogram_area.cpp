#include <bits/stdc++.h>
using namespace std;

int n,arr[50];

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
      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
      max_area = max(max_area,area_with_top);
    }
  }
  // Pop the remaining bars from stack and calculate area with every popped bar as the smallest bar
  while (s.empty() == false){
    tp = s.top();
    s.pop();
    //calculate area with every popped bar as the smallest bar
    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
    max_area = max(max_area,area_with_top);
  }
  return max_area;
}



int main(){
  scanf("%d", &n);
  for(int i = 0; i <n;i++){
    scanf("%d",&arr[i]);
  }
  printf("%d", maxHistogramArea(arr));
}

//LITERALLY THE SAME AS THE SHOE SHOPPING QUESTION

#include <iostream>
#include <climits> // INT_MAX
#include <vector>
using namespace std;

int dp[105][105];
string names[105];

int maxNum(vector<int> sec){
  int max = sec[0];
  for(int thing : sec){
    if(thing > max){
      max = thing;
    }
  }
  return max;
}

int main(){
  int m,n;
  cin>>m>>n;
  int arr[n];
  for(int i = 0;i<n;i++){
    cin>>names[i];
    cin>>arr[i];
  }
  for(int s = 0 ; s < n; s++){
    for(int l = 0; l + s< n; l++){
      if(s == 0){
        dp[l][l+s] = arr[l];
      }else{
        dp[l][l+s] = INT_MAX;
        for(int i = 0; i < s; i++){
          if( s <=m){
            vector<int> temp;
            for(int b = 0; b < s;b++){
              temp.push_back(arr[l + b]);
            }
            int min1 = min(dp[l][l+s], maxNum(temp));
            dp[l][l+s] = min(dp[l][l+i] + dp[l+i+1][l+s], min1);
          }else{
            dp[l][l+s] = min(dp[l][l+s], dp[l][l+i] + dp[l+i+1][l+s]);
          }
        }
      }

      for(int i = 0;i<n;i++){
        for(int a = 0; a < n;a++){
          cout<<to_string(dp[i][a]) + " ";
        }
        cout<<endl;
      }
      cout<<endl;

    }
  }
}

#include <iostream>
#include <vector>
using namespace std;
int dp[2005][200];
//the second index size if the size of the options
vector<int> options;
int main(){
  int n,b,l,d;
  cin>>n;
  cin>>b>>l>>d;
  int br[b];
  int lu[l];
  int din[d];
  for(int i = 0 ; i < b;i++){
    cin>>br[i];
  }
  for(int i = 0 ; i < l;i++){
    cin>>lu[l];
  }
  for(int i = 0 ; i < d;i++){
    cin>>din[d];
  }

  for(int i = 0; i < b;i++){
    for(int a = i; a < l;a++){
      for(int y =a; y < d;y++){
        options.push_back(br[i] + lu[a] + din[y]);
      }
    }
  }

  for(int i = 0 ; i <= n; i++){
    for(int j = 0; (unsigned)j < options.size();j++){
      if(j == 0){
        dp[i][j] = 1; //one way to reach the current capacity. Purchase no meals!
      }else if(j >= options[i]){ // if the capacity of the meal plan can hold the capacity of the this meal
        dp[i][j] = dp[i-1][j] + dp[i][j-options[i]];
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

//now I have to traverse the dp array and then find out how much everything costs.
//the money left over is my initial starting sum minus the total cost of the meals.

//now I take the money left over and a brute force on the money left over (first on the breakfast items, then the lunch, and the dinner)
//I find the one with the least amount of money left over

//wait that won't work because I have to dp the number of ways that the brute force will... hmmm. Maybe I can try brute forcing and search for isntances
//of the cheapest option. (if there is 2 options on thel ast day for example, I can multiply the existing combinations by 2)


}

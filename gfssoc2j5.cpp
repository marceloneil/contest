#include <iostream>
using namespace std;
int n,q,countArr[500003][11];
int main(){
  cin>>n>>q;
  for(int i = 1;i <= n;i++){
    int temp;
    cin>>temp;
    for(int a = 1; a <= n;a++){
      countArr[i][a] = countArr[i-1][a];
    }
    countArr[i][temp] +=1;
  }
  for(int i = 1 ; i <= q;i++){
    int l,r,temp;
    cin>>l>>r;
    for(int a = 10; a >0; a--){
      temp = countArr[n][a] - countArr[r][a] + countArr[l-1][a];
      if(temp > 0){
        cout<<to_string(a) + " " + to_string(temp)<<endl;
        break;
      }
    }
  }
}

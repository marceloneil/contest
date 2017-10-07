//yeah prefix sum is a bit too slow
#include <iostream>
using namespace std;
int arr[200005]; // idx = m

int prefixSum[200005];

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  for(int i = 1; i <= m;i++){
    arr[i] = n;
  }
  for(int i = 0;i < m;i++){
    int l,r;
    cin>>l>>r;
    for(int a = l; a <= r; a++){
      arr[a] -=1;
    }
  }

  for(int i =1;i <= n;i++){
    if(i == 1){
      prefixSum[i] = arr[i];
    }else{
      prefixSum[i] = prefixSum[i-1] + arr[i];
    }
  }
  for(int i =0;i<=n;i++){
    for(int a = 1; a + i <=n;a++){
      if(prefixSum[a+i] - prefixSum[a] >= k){
        cout<<i<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
}

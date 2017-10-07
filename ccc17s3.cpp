#include <iostream>
#include <vector>
using namespace std;
int lengths[2005];
int sums[4010];
int n,numHeights;
int main(){
  cin>>n;
  for(int i = 0;i<n;i++){
    int temp;
    cin>>temp;
    lengths[i] = lengths[i] + 1;
  }
  for(int i =0;i<n;i++){
    for(int a =i;a<n;a++){
      sums[i + a] = sums[i + a] + min(lengths[i],lengths[a]);
    }
  }
  for(int i = 0; (unsigned)i < sizeof(sums);i++){
    if(sums)
  }
}

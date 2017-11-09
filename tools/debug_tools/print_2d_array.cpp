#include <bits/stdc++.h>
using namespace std;

int n;
void printArray(int arr[500][500]){
  for(int i = 1; i <=n;i++){
    for(int a = 1;a <=n;a++){
      cout<<to_string(arr[i][a]) + " ";
    }
    cout<<endl;
  }
}

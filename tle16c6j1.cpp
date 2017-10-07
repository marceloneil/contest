#include <iostream>
using namespace std;

int main(){
  int n,m,a;
  scanf("%d %d",&n,&m);
  scanf("%d",&a);
  int arr[10000];
  for(int i = 0 ; i < a; i++){
    int x,y;
    scanf("%d %d",&x,&y);
    arr[x] = y;
  }
  for(int i = 1; i < 10000; i++){
    if(n <= 0){
      printf("The printer melts at 1 second(s).");
      break;
    }else if(n > m){
      printf("The printer jams at 0 second(s).");
      break;
    }
    n--;
    n+= arr[i];
    if(n > m){
      printf("The printer jams at %d second(s).", i);
      break;
    }else if(n <= 0){
      printf("The printer melts at %d second(s).", i+1);
      break;
    }
  }
}

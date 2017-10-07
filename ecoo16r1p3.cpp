#include <iostream>
#include <vector>
using namespace std;

struct cart(){
  cart* next;
  int number;
  constructor(int num){
    number = num;
  }
}root,lastCart;

int main(){
  int n;
  cin>>n;
  vector<int> train;
  bool first = true;
  while(n--){
    int num;
    cin>>num;
    if(first){
      root = new cart(num);
      lastCart = root;
    }else{
      cart temp = new cart()
      lastCart->next = temp;
      lastCart = temp;
    }
  }
  int totalMoves = 0;
  for(int i = n-1;i>0;i--){
    cart findCart = root;
    cart prevCart = root;
    int cartsPassed = 0;
    while(findCart.next != null){
      if(findCart.value == i){
        prevCart.next = findCart.next;
        cart temp = root;
        root = new cart(i);
        root.next = temp;
        totalMoves+= cartsPassed;
        break
      }
      cartsPassed++;
      prevCart = findCart;
      findCart = findCart.next;
    }
  }

  /*for(int i = n-1;i>0;i--){
    for(int a = 0; a<n;a++){
      if(i == train[a]){
        int num = i;
        train[a].remove();
        train.push_back(a);
      }
    }
  }*/
}

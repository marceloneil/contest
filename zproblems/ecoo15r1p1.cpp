//don't forget to do a for loop wfor the 10 cases.
//but somehow this code isn't working. the while loop doesn't stop
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  for(int i = 0; i < 10;i++){
    int times = 0;
    int counts[8];
    for(int i = 0 ; i < 8; i++){
      counts[i] = 0;
    }
    string smartie;
    cin>>smartie;
    while(smartie != "end"){
      if(smartie == "orange"){
        counts[0]++;
      }else if(smartie == "blue"){
        counts[1]++;
      }else if(smartie == "green"){
        counts[2]++;
      }else if(smartie == "yellow"){
        counts[3]++;
      }else if(smartie == "pink"){
        counts[4]++;
      }else if(smartie == "violet"){
        counts[5]++;
      }else if(smartie == "brown"){
        counts[6]++;
      }else if(smartie == "red"){
        counts[7]++;
      }
      cin>>smartie;
    }
    //of box
    cin>>smartie;
    cin>>smartie;
    for(int i = 0; i < 8; i++){
      if(i == 7){
        times+= counts[i]*16;
      }else{
        times+=((ceil((double)counts[i]/7.0))*13);
      }
    }
    cout<<times<<endl;
  }
}

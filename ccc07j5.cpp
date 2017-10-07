//what the heck is this messed up question
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[40];
int main(){
  int mind,maxd,n;
  cin>>mind;
  cin>>maxd;
  cin>>n;
  vector<int> stops = {-1, 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
  for(int i = 0 ; i < n ; i++){
    int temp;
    cin>>temp;
    stops[i+14] = temp;
  }
  sort(stops.begin(), stops.end());

  arr[1] = 1; // there is one way to get to the first hotel
  for(int i = 1; (unsigned)i <= sizeof stops; i++){
    for(int j = i; j > 0; j--){
      int distBetween = stops[j] - stops[j-1];
      if(distBetween <= maxd && distBetween >= mind){
        //cout<<stops[j-1]<<endl;
        arr[i] += arr[j-1];
      }
    }
  }
  cout<<arr[sizeof stops]<<endl;
  /*for(int i = 0 ; (unsigned)i < stops.size(); i++){
    cout<<stops[i]<<endl;
  }
  cout<<endl;
  for(int i = 0 ; (unsigned)i < stops.size(); i++){
    cout<<arr[i]<<endl;
  }*/

}

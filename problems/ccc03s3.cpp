#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;
int r,c,w;
char arr[30][30];
int visited[30][30];

vector<pair<int,int> > needToSearch;

int findRoomSize(int x, int y){
  if(arr[x][y] == 'I' || visited[x][y]){
    return 0;
  }
  visited[x][y] = 1;
  int total = 1;
  total += findRoomSize(x,y-1);
  total += findRoomSize(x,y+1);
  total += findRoomSize(x-1,y);
  total += findRoomSize(x+1,y);
  return total;
}



int main(){

  for(int i = 0; i < 30; i++){
    for(int a = 0; a < 30; a++){
      arr[i][a] = 'I';
    }
  }


  cin>>w;
  cin>>r;
  cin>>c;
  for(int i = 0; i < r; i++){
    string temp;
    cin>>temp;
    for(int a = 0; a < c; a++){
      if(temp.at(a)== '.'){
          needToSearch.push_back(make_pair(i+1,a+1));
      }
      arr[i+1][a+1] = temp.at(a);
    }
  }
  vector<int> sizes;
  for(int i = 0; (unsigned)i < needToSearch.size(); i++){
    int wood = findRoomSize(needToSearch[i].first, needToSearch[i].second);
    if(wood){
      sizes.push_back(wood);
    }
  }
  //catch cases for plans with zero rooms, you with zero wood etc.
  sort(sizes.begin(), sizes.end());
  for(int i = sizes.size() -1; i > -1; i--){
    w = w-sizes[i];
    if(w < 0){
      if(sizes.size() - i -1 == 1){
        cout<< "1 room, " + to_string(w+sizes[i]) + " square metre(s) left over"<<endl;
      }else{
        cout<<to_string(sizes.size() - i -1 ) + " rooms, " + to_string(w+sizes[i])+ " square metre(s) left over"<<endl;
      }
      return 0;
    }
  }
  if(sizes.size() == 1){
    cout<< "1 room, " + to_string(w) + " square metre(s) left over"<<endl;
  }
  cout<< to_string(sizes.size()) + "rooms, " + to_string(w) + " square metre(s) left over"<<endl;
}

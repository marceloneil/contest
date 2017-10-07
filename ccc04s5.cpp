#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
int dp[105][105][2];

template<typename Out>
void split(const string &s, char delim, Out result){
  stringstream ss;
  ss.str(s);
  string item;
  while(getline(ss,item,delim)){
    *(result++) = item;
  }
}

vector<string> split(const string &s, char delim){
  vector<string> elems;
  split(s,delim,back_inserter(elems));
  return elems;
}
vector< string > arr;
int main(){
  string tbuffer;
  for(int i = 0; i < 105; i++){
    tbuffer += "*";
  }
  //this is a filler row
  arr.push_back(tbuffer);
  int n,m;
  cin>>m>>n;
  for(int i =1;i<=m;i++){
    string row;
    cin>>row;
    arr.push_back(row);
  }
  //.first = from up to down. .second = from down to up
  for(int x = 1; x <= n; x++){
    cout<<"wut"<<endl;
    for(int y = 1; y <= m;y++){//we are moving from up to down
      if(arr[x].at(y) != '*'){
        //the val above us, or the two vals from the lft of us
        //make the first column dull
        if(arr[x].at(y) != '.'){
          int val = arr[x].at(y);
          dp[x][y][1] =dp[x][y][1] + val;
          dp[x][y][2] =dp[x][y][2] + val;
        }
          dp[x][y][1] += max(dp[x][y-1][1],max(dp[x-1][y][1], dp[x-1][y][2]));
      }
    }
    cout<<"hi"<<endl;
    for(int y = m; y >= 1;y--){
      cout<<"yay"<<endl;
      if(arr[x].at(y) != '*'){
        dp[x][y][2] += max(dp[x][y-1][2],max(dp[x-1][y][1], dp[x-1][y][2]));
      }
    }
  }
  cout<<max(dp[n][m][1],dp[n][m][2])<<endl;
}






//wut

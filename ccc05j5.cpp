#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 2147483647
#define EPS 1e-9
#define PI 3.141592653589793238462
#define MOD 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define US (unsigned)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<VPII > VVPII;
typedef map<int,int> MII;

string wor;
map<string, bool> monkeyWords;

bool isAWord(string word);

bool checkIfMonkeyWord(string word){
  if(isAWord(word)){
    return true;
  }
  for(int i = 0; US i + 2 < sizeof word; i++){
    cout<<"yo"<<endl;
    if(checkIfMonkeyWord(word.substr(0, i)) && word[i+1] == 'N' && checkIfMonkeyWord(word.substr(i+2))){
      return true;
    }
  }

  return false;
}

bool isAWord(string word){
  if(word == "A"){
    return true;
  }
  if(word.size() > 2){
    if(word[0] == 'B' && word[word.size() - 1] == 'S'){
      return checkIfMonkeyWord(word.substr(1,word.size()-2));
    }
  }
  return false;
}

int main(){
  cin>>wor;
  while(wor != "X"){
    if(checkIfMonkeyWord(wor)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
    cin>>wor;
  }
}

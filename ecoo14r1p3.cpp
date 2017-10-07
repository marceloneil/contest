
#include <iostream>
#include <ctype.h> //needed for ispunct()
using namespace std;


string onlyLetters(string str){
    string retStr = "";

    for(int i = 0; (unsigned)i < str.length(); i++){
        if(!ispunct(str[i])){
            retStr += str[i];
        }
    }
  return retStr;
}
string board[30][30];
string visited[30][30];
//string words[100];

void findWord(string word,int l,int r,int dir){
  if(dir == 0){
      for(int i = 0;(unsigned)i<word.size();i++){
  }

  }
}

int main(){
  int r,c,m;
  cin>>r>>c;
  for(int i = 0; i < r;i++){
    for(int a = 0 ; a < c;a++){
      cin>>board[i][a];
    }
  }
  cin>>m;
  while(m--){
    string word;
    cin>>word;
    word = onlyLetters(word);
    int leng = word.size();
    for(int a = 0;a<r;a++){
      for(int b = 0;b<c;b++){
        if(board[a][b] == to_string(word.at(0))){
          if(a-leng >-1)findWord(word,a,b,0);
          if(a+leng < r)findWord(word,a,b,1);
          if(b-leng >-1)findWord(word,a,b,2);
          if(b+leng < r)findWord(word,a,b,3);
          if(a-leng >-1 && b-leng > -1)findWord(word,a,b,4);
          if(a-leng >-1 && b+leng < r)findWord(word,a,b,5);
          if(a+leng < r && b-leng > -1)findWord(word,a,b,6);
          if(a+leng < r && b+leng < r)findWord(word,a,b,7);
        }
      }
    }
  }
}

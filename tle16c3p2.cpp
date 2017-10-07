#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
int main(){
int p,n,v,r;
cin>>p>>n>>v>>r;

vector< vector<int> > deadPlanets;
vector<int> aValues;
vector< vector<int> > planets;
for(int i = 0 ; i < p ; i ++){
  int x,y;
  cin>>x>>y;
  vector<int> coords(x,y);
  planets[i] = coords;
}
for(int i = 0 ; i < n; i++){
  int a;
  cin>>a;
  aValues.push_back(a);
}
//loop through every x coord until v
for(int i = 0 ; i < v ; i ++){
  int sum = 0;
  //loop through every n value and generate a y value that would match the x value
  for(int f = n; f > 0; f--){
    sum +=  aValues[f]* pow(i,f);
  }
  for(int h = 0 ; h < planets.size(); h++){
    //check to see if it falls along on that function
    if(planets[h][0] == i && planets[h][1] == sum){
      //add it to the dead array
      if(!(deadPlanets[h][0] == planets[i][0] && deadPlanets[h][1] == planets[i][1])){
        deadPlanets[deadPlanets.size()] = planets[i];
      }
    }
  }
}
int explosiony = 0;
for(int f = n; f > 0; f--){
  explosiony +=  aValues[f]* pow(v,f);
}
//explosion area
for(int i = 0 ; i < p;i++){
  if( sqrt(pow(planets[i][0] - v,2) + pow(planets[i][1] - explosiony,2)) < r ){
    for(int a = 0 ; a < p; a++){
      //the planet isn't already dead
      if(!(deadPlanets[a][0] == planets[i][0] && deadPlanets[a][1] == planets[i][1])){
        deadPlanets[deadPlanets.size()] = planets[i];
      }
    }
  }
}
cout<<deadPlanets.size()<<endl;
}

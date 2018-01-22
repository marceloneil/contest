#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n = 0;
    bool e = false;
    while(true){
        string s;
        cin >> s;
        if(s == "not") n++;
        else{
            if(s == "True") e = true;
            break;
        }
    }
    if(n%2){
        if(e) printf("False");
        else printf("True");
    }else{
        if(e) printf("True");
        else printf("False");
    }
    return 0;
}

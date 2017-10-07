#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int counter = 0;
	node * children[30];

	node(){
		memset(children,0, sizeof(children));
	}
};
node * root = new node();

void insert(string &s){
	node * curr = root;
	for(int i = 0; i < s.length(); i++){
		if(!curr -> children[s[i] - 'a']){
			curr -> children[s[i] - 'a'] = new node();
		}
		curr = curr -> children[s[i] - 'a'];
		curr -> counter++;
	}
}

int query(string &s){
	node * curr = root;
	for(int i = 0; i < s.length(); i++){
		if(!curr -> children[s[i] - 'a']){
			return 0;
		}
		curr = curr -> children[s[i] - 'a'];
	}
	return curr -> counter;
}

int N,M;
string str;
int main() {
	cin >> N;
	while(N--){
		cin >> str;
		insert(str);
	}
	cin >> M;
	while(M--){
		cin >> str;
		cout << query(str) << "\n";
	}
	return 0;
}

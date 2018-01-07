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





int acount =0;
class trie {
  static const int ALPHABET_SIZE = 26;
  static int map_alphabet(char c) {
    return (int)(c - 'a');
  }
  struct node_t {
    bool leaf;
    node_t * children[ALPHABET_SIZE];
    node_t(): leaf(false) {
      for (int i = 0; i < ALPHABET_SIZE; i++)
      children[i] = 0;
    }
    bool is_free() {
      for (int i = 0; i < ALPHABET_SIZE; i++)
      if (this->children[i] != 0) return true;
      return false;
    }
  } *root;

  bool erase(const std::string & s, node_t * n, int depth) {
    if (n == 0) return false;
    if (depth == (int)s.size()) {
      if (n->leaf) {
        n->leaf = false;
        return n->is_free();
      }
    } else {
      int idx = map_alphabet(s[depth]);
      if (erase(s, n->children[idx], depth + 1)) {
        delete n->children[idx];
        return !n->leaf && n->is_free();
      }
    }
    return false;
  }
  static void clean_up(node_t * n) {
    if (n == 0 || n->leaf) return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    clean_up(n->children[i]);
    delete n;
  }
public:
  trie() { root = new node_t(); }
  ~trie() { clean_up(root); }
  void insert(const std::string & s) {
    node_t * n = root;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = map_alphabet(s[i]);
      if (n->children[c] == 0){
        n->children[c] = new node_t();
      }
      acount+=1;
      n = n->children[c];
    }
    n->leaf = true;
  }
  bool contains(const std::string & s) {
    node_t *n = root;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = map_alphabet(s[i]);
      if (n->children[c] == 0)
        return false;
      n = n->children[c];
    }
    return n != 0 && n->leaf;
  }
  bool erase(const std::string & s) {
    return erase(s, root, 0);
  }
};


int main(){
  int n;
  scanf("%d", &n);
  //vector<string> arr;
  trie t;
  for(int i = 0; i < n;i++){
    string temp;
    cin>>temp;
    t.insert(temp);
    //arr.push_back(temp);
  }
  cout<<acount<<endl;
}

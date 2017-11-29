sort (arr.begin(), arr.end(),greater<string>());
for(int i = 0;i<n;i++){
  cout<<arr.back()<<endl;
  arr.pop_back();
}

/*
struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
sort(ans.begin(), ans.end(),greater1());
*/

sort (arr.begin(), arr.end(),greater<string>());
for(int i = 0;i<n;i++){
  cout<<arr.back()<<endl;
  arr.pop_back();
}

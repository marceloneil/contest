//The upper bound binary search method should return the first x such that f(x) is strictly greater than the target

int binary_search_ub(int lo, int hi, int target){
  while(lo < hi){
    int mid = lo + (hi-lo)/2; // could replace with (lo+hi)/2 if too slow
    if (f(mid) > target){ // this could be replaces with an array instead of a fucntion
      hi = mid;
    }else{
      lo = mid+1;
    }
  }
  return lo;
}

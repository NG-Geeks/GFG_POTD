Print Pattern

Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.

Solution::
class Solution{
    void solve(int n,vector<int>&v){
        if(n<=0){
            v.push_back(n);
            return ;
        }
        v.push_back(n);
        solve(n-5,v);
        v.push_back(n);
    }
public:
    vector<int> pattern(int N){
          vector<int>v;
          solve(N,v);
          return v;
    
          
    }
};
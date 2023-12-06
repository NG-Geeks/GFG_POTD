How Many X's?

Given two integers L, R, and digit X. Find the number of occurrences of X in all the numbers in the range (L, R) excluding L and R.

Solution:: 
class Solution {
    int solve(int n , int &x){
        int cnt=0;
        while(n){
            if(n%10==x)cnt++;
            n/=10;
        }
        return cnt;
    }
  public:
    int countX(int L, int R, int X) {
        int cnt=0;
        for(int i = L+1 ; i<R;i++){
            cnt += solve( i , X);
        }
        return cnt;
    }
};
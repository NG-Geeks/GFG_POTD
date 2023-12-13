Consecutive 1's not allowed
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

Time Complexity::
    O(N)

Space Complexity::
    O(1)
   

Solution::
class Solution{
    const int mod = 1000000007;
public:
	// #define ll long long
	ll countStrings(int n) {
	    int zero =1;
	    int one =1;
	    int sum = one + zero;
	    while(--n){
	        one = zero;
	        zero = sum;
	        sum  = (one + zero)%mod;
	    }
	    return sum;
	}
};
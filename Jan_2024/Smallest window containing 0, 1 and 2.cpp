Question ::  Smallest window containing 0, 1 and 2



Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Solution::

Complexity
Time complexity:
    O(N )
Space complexity:
    O(1 )
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
  public:
    int smallestSubstring(string &s) {
        vector<int>f(3,0);
        int ans = INT_MAX;
        int i =0 , j = 0 ;
        bool ok = 0;
       while(j<s.length() or i<j){
            if(!ok && j<s.length()){
                ++f[s[j++] - '0'];
                if(f[0] && f[1] && f[2])ok=1;
                else ok =0;
                
            }
            else if(i<j){
                --f[s[i++] - '0'];
                if(f[0] && f[1] && f[2]) ok= 1;
                else ok=0;
            }
            if(ok)ans = min(ans , j-i);
        }
        return (ans == INT_MAX)?-1:ans;
    }
};
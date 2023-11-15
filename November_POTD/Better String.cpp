Better String

Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.
 Solution::
class Solution {
  int solve(string &s){
      unordered_map<char , int>m;
      vector<int>dp(s.length()+1);
      dp[0]=1;
      for(int i=1;i<dp.size();i++){
          dp[i] = 2*dp[i-1];
          char c = s[i-1];
          if(m.find(c)!=m.end()){
              int k = m[c];
              dp[i] -=dp[k-1];
          }
          m[c] = i;
      }
      return dp[s.size()];
  }
  public:
    string betterString(string str1, string str2) {
       if(solve(str1)>=solve(str2))return str1;
       return str2;
    }
};
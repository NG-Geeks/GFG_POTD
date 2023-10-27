Ques.  Minimum Number Of Deletions to make string Palindrome

class Solution{
   int LongestCommonSubsequence(string &s ,string &t ){

       vector<int>curr(s.length()+1,0);
       vector<int>next(s.length()+1,0);
       
       for(int i= s.length()-1;i>=0;i--){
           
           for(int j= t.length()-1;j>=0;j--){
               
               int ans =0;
               
               if(s[i] == t[j])
                   ans = 1 + next[j+1];
               else
                   ans = max(next[j] , curr[j+1]);
             
               curr[j] = ans;
           }
           next = curr;
       }
     return next[0];
   }
  public:
    int minimumNumberOfDeletions(string &s) { 
        string t = s;
        reverse(t.begin() , t.end());
        
        int k =  LongestCommonSubsequence(s , t);
        return s.length() -  k;
        
    } 
};
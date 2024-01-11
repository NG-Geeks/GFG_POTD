Question :: Remove K Digits
MediumAccuracy: 26.8%  Submissions: 38K+    Points: 4

Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.
Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)


Code::
class Solution {
  public:
    string removeKdigits(string S, int k) {
        stack<char>st;
        for(char &c:S){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k-=1;
            }
            if(!st.empty() or c!='0' )st.push(c);
            
        }
        
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty())return "0";
        
        int n = S.size();
        while(!st.empty()){
            S[n-1] = st.top();
            st.pop();
            n-=1;
        }
        return S.substr(n);
    }
};
Question :: Winner of an election

Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.


Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)
Code
#pragma gcc optimize("03")
auto init = [] (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        vector<string>v;
        int maxi = INT_MIN; 
        string s="";
        for(auto &i: m){
            if(i.second > maxi){
                 maxi = i.second;
                 s = i.first; 
              
            }
            if(i.second == maxi){
                if(i.first<s)s = i.first;
            }
        } 
        v.push_back(s);
        v.push_back(to_string(maxi));
        return v;      
    }
};

Question :: All Unique Permutations of an array
MediumAccuracy: 52.85%Submissions: 13K+Points: 4
Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Solution::

Complexity
Time complexity:
    O(N^2)
Space complexity:
    O(N)
CODE::
class Solution {
      void solve( set<vector<int>>&ans,vector<int>nums,int index){
        
        //base case jaha par recursion end hoga
        if(index==nums.size()-1){
            ans.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
        
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &nums ,int n) {
        set<vector<int>>ans;
         vector<vector<int>>res;
        int index=0;
        solve(ans,nums,index);
        for(auto &i:ans){
            res.push_back(i);
        }
        return res;
    }
};
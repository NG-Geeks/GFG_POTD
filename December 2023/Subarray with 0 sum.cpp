Subarray with 0 sum

Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.Time Complexity::
    O(N)

Space Complexity::
    O(N)
   

Solution::
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        set<int >s;
           int prefixsum=0;
           for(int i=0;i<n;i++){
                prefixsum+=arr[i];
                
                if(prefixsum==0)return 1;
                
                if(s.find(prefixsum)!=s.end())return 1;
                s.insert(prefixsum) ;
                
               
           }
         
           return 0;
    }
};
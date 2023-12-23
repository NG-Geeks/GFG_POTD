Question :: Count More than n/k Occurences

Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more than n/k times.

Solution::
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        k = n/k;
        unordered_map<int, int>m;
        for(int i=0;i<n;i++)m[arr[i]]++;
        int cnt =0;
        for(auto &i:m){
            if(i.second>k)cnt++;
        }
        return cnt;
    }
};

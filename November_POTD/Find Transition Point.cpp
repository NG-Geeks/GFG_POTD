Find Transition Point
Given a sorted array containing only 0s and 1s, find the transition point, i.e., the first index where 1 was observed, and before that, only 0 was observed.

Solution::
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        int s=0 , e = n-1;
        int mid = (s+e)/2;
        while(s<=e){
            if(arr[mid]==0 && arr[mid+1]==1)return mid+1;
            else if (arr[mid]==0)s = mid+1;
            else if(arr[mid]==1)e = mid-1;
            mid = (s+e)/2;
        }
        return (mid==0 && arr[mid]==1) ?0:-1;
    }
};
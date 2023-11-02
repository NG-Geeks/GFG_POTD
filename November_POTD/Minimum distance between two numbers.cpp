Minimum distance between two numbers

You are given an array a, of n elements. Find the minimum index based distance between two distinct elements of the array, x and y. Return -1, if either x or y does not exist in the array

class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        int mini = INT_MAX;
        int l=-1;
        int r=-1;
         for(int i=0;i<n;i++){
             if(arr[i]==x){
                l = i;
                if(r!=-1)mini  = min(mini , abs(l-r));
                }
            else if(arr[i]==y){
                r = i;
                if(l!=-1)mini = min(mini , abs(l-r));
            }
             
         }
         if(l==-1 or r==-1)return -1;
         return mini;
    }
};
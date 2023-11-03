Pythagorean Triplet

Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.
Solution::
class Solution{
public:
	bool checkTriplet(int arr[], int n) {
	    sort(arr , arr+n);
	    for(int i=0;i<n;i++){
	        arr[i] = arr[i]*arr[i];
	    }
	    for(int i= n-1;i>=2;i--){
	        int l=0;
	        int r =i-1;
	        while(l<r){
	            if(arr[l]+arr[r] == arr[i])return 1;
	            else if(arr[l] + arr[r]>arr[i])r--;
	            else l++;
	        }
	    }
	    return 0;
	}
};
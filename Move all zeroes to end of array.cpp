Move all zeroes to end of array

Problem ::
Given an array arr[] of n positive integers. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in-place.
Solution::
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	      int i=0 ,  j=1;
	   
	    while(j<n){
	        while(i<n && arr[i]!=0)i++;
	       	        j = (j<=i)?i+1:j++;

	         while(j<n && arr[j]==0)j++;
	        if(i<n && j<n)
	        swap(arr[i],arr[j]);
	        i++;
	       
	        if(j==n)break;
	}
	}
};
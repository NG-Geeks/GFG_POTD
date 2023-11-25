Shuffle integers
Given an array arr of n elements in the following format {a1, a2, a3, a4, ... , an/2, b1, b2, b3, b4, ... , bn/2}, the task is shuffle the array to {a1, b1, a2, b2, a3, b3, ... , an/2, bn/2} without using extra space.
Note that n is even.
class Solution{
	public:
	void shuffleArray(int arr[],int n)
	{
	    for(int i=0;i<n;i++){
	        int cur = arr[i];
	        int curpos = i;;
	        while(cur>0){
	            int newpos = (curpos<n/2)?2*curpos : 2*(curpos-n/2)+1;
	            int newnum = arr[newpos];
	            arr[newpos] = -cur;
	            cur = newnum;
	            curpos = newpos;
	        }
	    }
	    for(int i =0 ;i<n;i++){
	        if(arr[i]<0)arr[i] = -arr[i];
	        }
	}
};
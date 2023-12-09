Smith Number
Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.
Time Complexity::
    O(sqrt(N))

Space Complexity::
   O(n)
   

Solution::

class Solution {
    int s(int n){
         int sum =0;
        while(n){
            sum +=n%10;
            n/=10;
        }
        return sum;
    }
    vector<int> primefactor(int n){
        if(n<=2)return {};
        int l =n;
        vector<int>v;
        while(n%2==0){
        v.push_back(2);
        n = n/2;
        }
        for(int i=3;i<=sqrt(n);i=i+2){
          while (n % i == 0)  
        {  
            v.push_back(i);
            n = n/i;  
        }  
        }
        if(n>2 && l!=n)v.push_back(n);
        return v;
    }
  public:
    int smithNum(int n) {
       int k= s(n);
       vector<int>v = primefactor(n);
       int sum =0;
       for(int &i:v){
           sum += s(i);
       }
       return k==sum;
    }
};
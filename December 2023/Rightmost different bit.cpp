Rightmost different bit

Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.Time Complexity::
    O(N)

Space Complexity::
    O(1)
   

Solution::
class Solution
{   string binary(int n){
    string s;
    for(int i=31;i>=0;i--){
        bool k = (1<<i)&n;
        s+=to_string(k);
    }
    return s;
}
    public:
    int posOfRightMostDiffBit(int m, int n)
    {
       string s , t;
      s =  binary(m);
      t = binary(n);
       int cnt=0;
       for(int i=31;i>=0;i--){
           if(s[i]!=t[i])return 31-i+1;
           cnt++;
       }
       return -1;
    }
};
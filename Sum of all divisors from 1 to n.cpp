Sum of all divisors from 1 to n
LINK->https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
Given a positive integer N., The task is to find the value of    \sum_{i=1}^{i=n} F(i)  where function F(i) for the number i is defined as the sum of all divisors of i.
Solution::

class Solution{
public:
    long long sumOfDivisors(int n)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += n / i * i;
        }
        return sum;
    }
};
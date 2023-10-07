Question-- >> Count number of substrings

                  https : // practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
                          //   User function template for C++

                          class Solution
{
public:
    long long int upto(string s, int k)
    {
        int b = 0, p = 0, count = 0;
        long long ans = 0;
        vector<int> ab(26, 0);
        while (p < s.length())
        {
            ab[s[p] - 'a']++;
            if (ab[s[p] - 'a'] == 1)
                count++;
            while (count > k)
            {
                ab[s[b] - 'a']--;
                if (ab[s[b] - 'a'] <= 0)
                {
                    count--;
                }
                b++;
            }
            ans += p - b + 1;
            p++;
        }
        return ans;
    }
    long long int substrCount(string s, int k)
    {
        return upto(s, k) - upto(s, k - 1);
    }
};
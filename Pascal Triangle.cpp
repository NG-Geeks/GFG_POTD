Pascal Triangle
Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 109 + 7.

class Solution{
    const int mod = 1e9+7;
public:
    vector<long long> nthRowOfPascalTriangle(int numRows) {
       vector<vector<long long >>ans(numRows);

        for(int i=0;i<numRows;i++){
            vector<long long >r(i+1);
            for(int j=0 ; j<i+1 ; j++){
                if(j==0 || j==i)r[j]  = 1;
                else{
                    r[j] = (ans[i-1][j-1] + ans[i-1][j])%mod;
                }  
            }
            ans[i] = (r);
        
        }
        return ans[numRows-1];
    }
};
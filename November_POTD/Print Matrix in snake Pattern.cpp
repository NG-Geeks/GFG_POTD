Print Matrix in snake Pattern
Given a matrix of size N x N. Print the elements of the matrix in the snake like pattern depicted below.



Solution::
class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int> v;
        bool f=1;
        for(int i=0;i<matrix.size();i++){
            if(f){
            for(int j=0;j<matrix[0].size();j++){
                    v.emplace_back(matrix[i][j]);
            }
            }
            else{
                for(int j= matrix[0].size()-1;j>=0;j--){
                    v.emplace_back(matrix[i][j]);
                }
            }
            f=!f;
        }
        return v;
    }
};
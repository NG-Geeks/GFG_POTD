Question :: Search Pattern (KMP-Algorithm)

Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.


Solution::

Complexity
Time complexity:
    O(N + M).
Space complexity:
    O(1)


Code::

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>v;
           for(int i= 0 ;i<txt.size() ; i++){
               if(txt[i] == pat[0]){
                   int j =0;
                   int  k=i;
                   while( k<txt.length() && txt[k] == pat[j]){
                       k++;
                       j++;
                   }
                   if(j==pat.length())v.push_back(i+1);
               }
           }
           return v;
        }
     
};
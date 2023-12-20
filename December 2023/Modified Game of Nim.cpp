Modified Game of Nim

    You are given an array A of n elements.There are two players player 1 and
    player 2. A player can choose any of element from an array and remove it.If the bitwise XOR of all remaining elements equals 0 after removal of the selected element,
    then that player loses.Find out the winner if player 1 starts the game and they both play their best.O(N)

        Space Complexity::
            O(1)

 Solution::
class Solution
{
    bool check(map<int,int>&m){
        if(m.size()==0)return 0;
        int x = 0;
        for(auto &i:m)
{
    if (i.second & 1)
    {
        x = x ^ i.first;
    }
}
return x == 0;
}
void remove(map<int, int> &m)
{
    for (auto &i : m)
    {
        if (i.second & 1)
        {
            m[i.first]--;
            if (m[i.first] == 0)
                m.erase(i.first);
            break;
        }
    }
}

public:
int findWinner(int n, int a[])
{
    // map<int,int>m;
    // for(int i=0;i<n;i++){
    //     m[a[i]]++;
    // }
    // bool k=1;
    // while(m.size()){
    //     if( k && check(m) )return 1;
    //     if(!k && check(m))return 2;
    //     remove(m);
    //     k = !k;
    // }
    //  if( k && check(m)==0 )return 1;
    //  if(!k && check(m)==0)return 2;

    // 2nd approach
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= a[i];
    return n & 1 && ans > 0 ? 2 : 1;
}
};
Question ::  Vertex Cover
HardAccuracy: 62.97%Submissions: 19K+Points: 8

Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.


Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(1)

Code::
class Solution{
    public:
    
    int next(int x){
        unsigned smallest, ripple, new_smallest, ones;

        if (x == 0) return 0;
        smallest     = (x & -x);
        ripple       = x + smallest;
        new_smallest = (ripple & -ripple);
        ones         = ((new_smallest/smallest) >> 1) - 1;
        return ripple | ones;
    }
    
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int ans = 20;
        
        auto check = [&](int bits) -> bool {
            int cur = (1 << bits) - 1;
            
            while(cur < (1 << n)){
                int m = edges.size();
                
                for(auto edge : edges){
                    int x, y;
                    tie(x, y) = edge;
                    --x; --y;
                    
                    if(((cur >> x) & 1) or ((cur >> y) & 1))
                        --m;
                }
                
                if(m == 0)
                    return 1;
                    
                cur = next(cur);
            }
            
            return 0;
        };
        
        int low = 0;
        int high = n;
        
        while(low < high - 1){
            int mid = low + (high - low) / 2;
            
            if(check(mid))
                high = mid;
            else
                low = mid;
        }
        
        return high;
    }
};
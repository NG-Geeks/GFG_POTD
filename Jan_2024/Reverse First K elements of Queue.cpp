Question :: Reverse First K elements of Queue
EasyAccuracy: 81.28%Submissions: 98K+Points: 2

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.


Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(K)


Code::
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        deque<int>v;
        k = k %(q.size()+1);
        int n = q.size() - k;
        
        while(k--){
            v.push_back(q.front());
            q.pop();
        }
        
        while(!v.empty()){
            q.push(v.back());
            v.pop_back();
        }
        while(n--){
            int l  = q.front();
            q.pop();
            q.push(l);
        }
        return q;
    }
};
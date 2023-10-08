Question-- >> Insert in a Sorted List
                  https : // practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
                          Given a linked list sorted in ascending order and an integer called data,
    insert data in the linked list such that the list remains sorted.

    struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node *head, int data)
    {
        if (!head || head->data >= data)
        {
            Node *n = new Node(data);
            n->next = head;
            return n;
        }
        Node *temp = head;
        while (temp->next && temp->next->data <= data)
        {
            temp = temp->next;
        }
        if (temp->next == NULL && temp->data <= data)
        {
            Node *n = new Node(data);
            temp->next = n;
            return head;
        }
        Node *n = new Node(data);
        Node *next = temp->next;
        temp->next = n;
        n->next = next;
        return head;
    }
};
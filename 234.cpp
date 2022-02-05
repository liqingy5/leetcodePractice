#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //     ListNode* left;
    //     bool isPalindrome(ListNode* head) {
    //         left = head;
    //         return reverse(head);
    //     }

    //     bool reverse(ListNode* right){
    //         if (right == nullptr) return true;
    //         bool res = reverse(right->next);
    //         res =res &&(left->val==right->val);
    //         left=left->next;
    //         return res;
    //     }

    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (fast != nullptr)
            slow = slow->next;
        ListNode *left = head, *right = reverse(slow);
        cout << right->val << endl;
        cout << left->val << endl;
        while (right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *right)
    {
        ListNode *prev = nullptr, *curr = right, *next = right;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main()
{
    ListNode *next = new ListNode(2);
    ListNode *head = new ListNode(1, next);
    Solution solution;
    cout << solution.isPalindrome(head) << endl;
}
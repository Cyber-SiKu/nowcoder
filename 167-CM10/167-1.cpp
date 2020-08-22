#include <cstdlib>
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Remove
{
public:
    bool removeNode(ListNode *pNode)
    {
        // write code here
        ListNode *next = pNode->next;
        if (next == NULL)
        {
            return false;
        }
        while (next->next != NULL)
        {
            pNode->val = next->val;
            pNode = next;
            next = pNode->next;
        }
        delete pNode->next;
        pNode->next = NULL;

        return true;
    }
};
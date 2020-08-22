#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
    ~ListNode()
    {
        delete next;
    }
};
class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (k == 0)
        {
            return NULL;
        }
        stack<ListNode *> s;
        ListNode *p = pListHead;
        while (p != NULL)
        {
            s.push(p);
            p = p->next;
        }
        for (size_t i = 0; i < k && !s.empty(); ++i)
        {
            p = s.top();
            s.pop();
        }
        if (s.empty())
        {
            p = NULL;
        }
        return p;
    }
};

int main()
{
    ListNode l(100);
    ListNode *p = &l;
    for (size_t i = l.val - 1; i >= 1; --i, p = p->next)
    {
        p->next = new ListNode(i);
    }

    p = Solution().FindKthToTail(&l, 1);
    cout << p->val << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
    int m_nKey;
    ListNode *m_pNext;
    ListNode()
    {
        m_nKey = 0;
        m_pNext = nullptr;
    }
    ~ListNode()
    {
        if (m_pNext != nullptr)
        {
            delete m_pNext;
        }
    }
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    ListNode *ret = pListHead;
    for (size_t i = 0; i < k; i++, ret = ret->m_pNext)
    {
        /* code */
    }
    return ret;
}

int main()
{
    int n;
    while (cin >> n)
    {
        ListNode *Head = new ListNode(); // 第一个为空节点
        ListNode *p = Head;
        for (size_t i = 0; i < n; i++)
        {
            p->m_pNext = new ListNode();
            cin >> p->m_pNext->m_nKey;
            p = p->m_pNext;
        }
        int k = 0;
        cin >> k;
        ListNode *out = FindKthToTail(Head, n - k + 1);
        cout << out->m_nKey << endl;
        delete Head;
        Head = nullptr;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
    ListNode *plusAB(ListNode *a, ListNode *b) {
        // write code here
        int tmp = a->val + b->val;
        int next = tmp / 10;
        ListNode *c = new ListNode(tmp % 10);
        ListNode *p = c;
        for (a = a->next, b = b->next; a != NULL || b != NULL;) {
            tmp = next;
            if (a != NULL) {
                tmp += a->val;
                a = a->next;
            }
            if (b != NULL) {
                tmp += b->val;
                b = b->next;
            }
            next = tmp / 10;
            p->next = new ListNode(tmp % 10);
            p = p->next;
        }
        if (next != 0) {
            p->next = new ListNode(next);
        }
        return c;
    }
};

int main() {
    ListNode a(0);a.next = new ListNode(1);
    a.next->next = new ListNode(1);
    ListNode b(0);
    ListNode* c = Plus().plusAB(&a, &b);
    return 0;
}

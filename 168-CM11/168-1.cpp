#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ~ListNode() {
        if (this->next != NULL) {
            delete this->next;
            this->next = NULL;
        }
    }
};

class Partition {
public:
    ListNode *partition(ListNode *pHead, int x) {
        // write code here
        ListNode *ret = new ListNode(-1);
        ListNode *insertPosition = ret; // < x 该节点插入， 大于尾插入
        for (ListNode *p = pHead; p != NULL; p = p->next) {
            if (p->val < x) {
                // < x
                insertPosition->val = p->val;
                ListNode *tmp = insertPosition->next;
                insertPosition->next = new ListNode(-1);
                insertPosition = insertPosition->next;
                insertPosition->next = tmp;
            } else {
                // >=x
                ListNode *tmp = insertPosition;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = new ListNode(-1);
                tmp->next->val = p->val;
            }
        }
        if (insertPosition == ret) {
            // 没有比x小的
            ret = insertPosition->next;
        } else {
            ListNode *p;
            for (p = ret; p->next != insertPosition; p = p->next);
            p->next = insertPosition->next;
        }
        insertPosition->next = NULL;
        delete insertPosition;
        return ret;
    }
};

int main() {
    ListNode l(11);
    ListNode *p = &l;
    for (int i = 10; i >= 0; --i, p = p->next) {
        p->next = new ListNode(i);
    }
    for (p = Partition().partition(&l, 7); p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    delete p;
    return 0;
}

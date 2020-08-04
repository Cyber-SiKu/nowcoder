#include <iostream>
#include <cstdlib>

using namespace std;

class ListNode
{
public:
	int m_nKey;
	ListNode *m_pNext;

	ListNode() {
		this->m_nKey = 0;
		this->m_pNext = nullptr;
	}

	void insert(int target, int value) {
		ListNode *p = this;
		while (p != nullptr && p->m_nKey != target) {
			p = p->m_pNext;
		}
		if (p != nullptr) {
			ListNode *next = p->m_pNext;
			p->m_pNext = new ListNode();
			p->m_pNext->m_nKey = value;
			p->m_pNext->m_pNext = next;
		}
	}

	static void deleteNode(ListNode *l, int deletValue) {
		if (l->m_nKey == deletValue) {
			ListNode *pre = l;
			l = l->m_pNext;
			delete pre;
		} else {
			ListNode *pre = l;
			while (pre->m_pNext->m_nKey != deletValue) {
				pre = pre->m_pNext;
			}
			ListNode *del_p = pre->m_pNext;
			pre->m_pNext = pre->m_pNext->m_pNext;
			del_p->m_pNext = nullptr;
			delete del_p;
		}
	}

	static void showList(ListNode *l) {
		while (l != nullptr) {
			cout << l->m_nKey << " ";
			l = l->m_pNext;
		}
		cout << endl;
	}

	~ListNode() {
		delete m_pNext;
	}
};


int main(int argc, char **argv) {
	int n;
	cin >> n;

	ListNode *l = new ListNode();
	cin >> l->m_nKey;

	for (int i = 0; i < n - 1; ++i) {
		int target, value;
		cin >> value >> target;
		l->insert(target, value);
	}

	int deletValue;

	cin >> deletValue;

	ListNode::deleteNode(l, deletValue);

	ListNode::showList(l);

	delete l;

	return 0;
}

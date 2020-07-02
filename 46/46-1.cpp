/**
 * 运行时间：3ms
 * 占用内存：388k
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    const int MAX = 1024;
    vector<int> tree;
    int length;
    int height;
    vector<int> leaf;

public:
    Solution(const vector<int>& data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    void insert_tree(const int& root, const vector<int>& sequence, const vector<int>& in_order);

    // 对 tree 先序遍历输出（无 endl）
    void preorder(ostream& os) const;

    // 对 tree 后序遍历
    void postorder(ostream& os) const;
};

Solution::Solution(const vector<int>& data)
{
    int lenth = data.size() / 2;
    this->length = lenth << 2;
    tree.resize(this->length, 0);

    vector<bool> manage(lenth, false); // 是否安排入树

    vector<int>::const_iterator start = data.cbegin();
    vector<int>::const_iterator middle = data.cbegin() + lenth;
    vector<int>::const_iterator end = data.cend();
    vector<int> sequence(start, middle);
    vector<int> in_order(middle, end);

    this->height = 0;

    this->insert_tree(0, sequence, in_order);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    for (const int& i : s.leaf) {
        os << i << " ";
    }
    os << endl;
    s.preorder(os);
    os << endl;

    s.postorder(os);
    os << endl;
    return os;
}

void Solution::insert_tree(const int& root, const vector<int>& sequence, const vector<int>& in_order)
{
    if (sequence.size() == 1) {
        this->leaf.push_back(sequence[0]);
    }

    int root_value = sequence[0];
    this->tree[root] = root_value;
    vector<int>::const_iterator root_itr = find(in_order.cbegin(), in_order.cend(), root_value);
    vector<int> left_in_order(in_order.cbegin(), root_itr);
    vector<int> right_in_order(root_itr + 1, in_order.cend());

    vector<int> left_sequence;
    vector<int> right_sequence;
    int count = 0, left_all = left_in_order.size();
    vector<int>::const_iterator i = sequence.cbegin() + 1, e_i = sequence.cend();
    for (; i != e_i; i++) {
        if (find(left_in_order.cbegin(), left_in_order.cend(), *i) != left_in_order.cend()) {
            left_sequence.push_back(*i);
            count++;
            if (count == left_all) {
                ++i;
                break;
            }
        } else {
            right_sequence.push_back(*i);
        }
    }
    right_sequence.insert(right_sequence.cend(), i, sequence.cend());

    if (!left_sequence.empty()) {
        this->insert_tree(root * 2 + 1, left_sequence, left_in_order);
    }
    if (!right_sequence.empty()) {

        this->insert_tree(root * 2 + 2, right_sequence, right_in_order);
    }
    if (!left_sequence.empty() || !right_sequence.empty()) {
        this->height++;
    }
}

void Solution::preorder(ostream& os) const
{
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        int pos = s.top();
        s.pop();
        cout << this->tree[pos] << " ";
        int root = pos * 2 + 2;
        if (this->tree[root] != 0 && root <= this->length) {
            s.push(root);
        }
        root = pos * 2 + 1;
        if (this->tree[root] != 0 && root <= this->length) {
            s.push(root);
        }
    }
}

void Solution::postorder(ostream& os) const
{
    stack<int> s1;
    vector<bool> visited(this->length, false);
    s1.push(0);

    while (!s1.empty()) {
        int pos = s1.top();
        int left = pos * 2 + 1;
        if (this->tree[left] != 0 && visited[left] == false && left <= this->length) {
            s1.push(left);
            continue;
        }
        int right = pos * 2 + 2;
        if (this->tree[right] != 0 && visited[right] == false && right <= this->length) {
            s1.push(right);
            continue;
        }

        os << this->tree[pos] << " ";
        s1.pop();
        visited[pos] = true;
    }
}

int main(int argc, char* argv[])
{
    vector<int> data;
    int i;
    while (cin >> i) {
        data.push_back(i);
    }

    Solution s(data);

    cout << s;
    return 0;
}
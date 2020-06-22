/**
 * 算法思想：
 *  使用 mulitset 保存 订单号+入店时间 订单号+出店时间
 *  由于 mulitset 中是有序并且是使用红黑树实现的,所以查找时间为log(nl)
 * 运行时间：3ms
 * 占用内存：480k
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class DataType {
public:
    int order;
    int data;
    DataType(const int& order, const int& data)
        : order(order)
        , data(data)
    {
    }
    friend bool operator<(const DataType& a, const DataType& b);
};

bool operator<(const DataType& a, const DataType& b)
{
    return a.data < b.data;
}

struct compare {
    bool operator()(const int& a, const int& b)
    {
        return a > b;
    }
};

class Solution {
private:
    priority_queue<int, vector<int>, compare> data; // 保存符合的订单

public:
    Solution(const multiset<DataType>& data_in,
        const multiset<DataType>& data_out,
        const int& A);
    ~Solution();
    friend ostream& operator<<(ostream& os, Solution& s);
};

Solution::Solution(const multiset<DataType>& data_in,
    const multiset<DataType>& data_out,
    const int& A)
{
    multiset<DataType>::const_iterator pos_in = data_in.upper_bound(DataType(0, A)); // 找到第一个入店时间大于A的订单
    multiset<DataType>::const_iterator pos_out = data_out.lower_bound(DataType(0, A)); // 找到第一个出店时间大于等于A的订单

    vector<int> order_in;
    for (multiset<DataType>::const_iterator i = data_in.begin(), e = pos_in; i != e; ++i) {
        order_in.push_back(i->order);
    }

    for (multiset<DataType>::const_iterator i = pos_out, e = data_out.end(); i != e; ++i) {
        // order_out.push_back(i->order);
        if (find(order_in.begin(), order_in.end(), i->order) != order_in.end()) {
            data.push(i->order);
        }
    }
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, Solution& s)
{
    if (s.data.empty()) {
        os << "null" << endl;
        return os;
    }
    while (!s.data.empty()) {
        /* code */
        os << s.data.top() << endl;
        s.data.pop();
    }

    return os;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    int A;
    cin >> A;
    // auto comp = [](DataType a, DataType b) { return a.data < b.data; };
    // multiset<DataType, decltype(comp)> data_1;
    // multiset<DataType, decltype(comp)> data_2;
    multiset<DataType> data_in;
    multiset<DataType> data_out;
    int order, in, out;
    for (size_t i = 0; i < n; i++) {
        cin >> order >> in >> out;
        data_in.insert(DataType(order, in));
        data_out.insert(DataType(order, out));
    }
    Solution s(data_in, data_out, A);

    cout << s;
    return 0;
}
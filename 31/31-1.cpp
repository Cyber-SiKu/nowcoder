/**
 * 算法思想：
 *  使用一个队列
 * 
*/
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

using DataType = list<pair<int, int>>;
using HashMap = unordered_map<int, DataType::iterator>;

class Solution {
private:
    // 根据 key 返回 value 所在data的迭代器
    HashMap map;
    DataType data;
    int size;

public:
    Solution(int n);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    int get(int key);
    void put(int key, int value);
};

Solution::Solution(int n)
    : size(n)
{
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    return os;
}

int Solution::get(int key)
{
    if (map.find(key) != map.end()) {
        // 存在数据
        DataType::iterator it = map[key];
        data.splice(data.end(), data, it);
        return it->second;
    }
    return -1;
}

void Solution::put(int key, int value)
{
    if (map.find(key) != map.end()) {
        // 存在该数据
        map[key]->second = value;
    } else if (size) {
        if (map.size() == size) {
            // 数据区已满
            map.erase(data.begin()->first);
            data.erase(data.begin());
        }
        map[key] = data.insert(data.end(), make_pair(key, value));
    }
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Solution s(n <= 0 ? 0 : n);

    char op;
    int a, b;
    while (cin >> op) {
        switch (op) {
        case 'p':
            cin >> a >> b;
            s.put(a, b);
            break;
        case 'g':
            cin >> a;
            cout << s.get(a) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
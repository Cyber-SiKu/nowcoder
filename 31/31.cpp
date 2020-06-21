/**
 * 算法思想：
 *  使用一个队列
 * 
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    // 记录访问的数据
    // 访问数据时，除了被访问的数据外都增加1
    // 替换数据时，找到最大的元素替换 被替换的数据 = 0
    vector<int> visted;

    // 根据 key 返回 value 所在数组下标
    unordered_map<int, int> map;
    // 保存与map相反的数据
    unordered_map<int, int> re_map;

    // 数据
    vector<int> data;

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
    , visted(n, -1)
    , data(n, 0)
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
    if (map.find(key) == map.end() || map.at(key) == -1) {
        // 没有该元素 或者该元素已经被剔除
        return -1;
    }
    int pos = this->map[key];
    int ret = this->data[pos];
    this->visted[pos]--;
    for (size_t i = 0, e = visted.size(); i < e; i++) {
        this->visted[i]++;
    }

    return ret;
}

void Solution::put(int key, int value)
{
    if (map.find(key) != map.end() && map[key] != -1) {
        /* key存在 */
        int pos = this->map[key];
        this->data[pos] = value;
        visted[pos] = 0;
        return;
    }
    /* key 不存在 */

    // 寻找插入点
    int max = visted[0];
    int max_pos = 0;
    if (max != -1) {
        for (size_t i = 1, e = visted.size(); i < e; i++) {
            if (visted[i] > max) {
                max = visted[i];
                max_pos = i;
            }
            if (visted[i] == -1) {
                max_pos = i;
                break;
            }
        }
    }

    // 插入数据
    if (visted[max_pos] != -1) {
        // 数据已满，替换数据
        int old_key = re_map[max_pos];
        re_map[max_pos] = -1;
        map[old_key] = -1;
        this->visted[max_pos] = -1;
    } else {
        // 数据未满插入数据
        map[key] = max_pos;
        re_map[max_pos] = key;
        this->visted[max_pos]--;
    }
    data[max_pos] = value;
    for (size_t i = 0, e = visted.size(); i < e; i++) {
        this->visted[i]++;
    }
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Solution s(n);

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
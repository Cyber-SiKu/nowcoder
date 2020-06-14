/**
 * 时间复杂度过大
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    /* data */
    vector<int> A; // A[1] 第i-1个城市的价格
    int max_income; // 最大收益
    int min_transations; // 最小交易次数

public:
    Solution(vector<int> data);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);

    // 返回到第i手中有一个,然后以此为起点到最后一个国家的最大收益max和最小交易次数min
    void f_1(int i, int& max, int& min);
    // 返回到第i手中没有神秘石,然后以此为起点到最后一个国家的最大收益max和最小交易次数min
    void f_0(int i, int& max, int& min);
};

Solution::Solution(vector<int> data)
    : A(data)
{
    this->f_0(0, this->max_income, this->min_transations);
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.max_income << " " << s.min_transations;
    return os;
}

void Solution::f_1(int i, int& max, int& min)
{
    if (i == this->A.size() - 1) {
        // 走到最后一个城市， 此时手中有一个,应该卖掉
        max = this->A[i];
        min = 1;
        return;
    }
    // 此时还不是最后一个城市，手中留有一个

    // 卖出，然后手中没有
    int max_sold, min_sold; // 用来保存如果卖出的结果
    this->f_0(i + 1, max_sold, min_sold);
    int income_sold = this->A[i] + max_sold; // 保存卖出的收益
    int translation_sold = min_sold + 1; // 卖出的收益的交易次数

    // 不卖出，手中仍然保留一个
    int max_no, min_no; // 用来保存不卖出的结果
    this->f_1(i + 1, max_no, min_no);
    int income_no = max_no; // 保存不卖出的收益
    int translation_no = min_no; // 保存不卖出的收益

    if (income_sold > income_no) {
        /* 卖出收益更高 */
        max = income_sold;
        min = translation_sold;
    } else if (income_sold < income_no) {
        /* 不卖出收益更高 */
        max = income_no;
        min = translation_no;
    } else {
        /* 收益持平 */
        max = income_sold;
        min = (translation_sold <= translation_no ? translation_sold : translation_no); // 交易次数选最小
    }
}

void Solution::f_0(int i, int& max, int& min)
{
    if (i == this->A.size() - 1) {
        // 走到最后一个城市， 此时手中没有神秘石 无需交易
        max = 0;
        min = 0;
        return;
    }
    // 此时还不是最后城市，手中没有

    // 买入，然后手中有一个神秘石
    int max_buy, min_buy; // 用来保存如果卖出的结果
    this->f_1(i + 1, max_buy, min_buy);
    int income_buy = max_buy - this->A[i]; // 保存卖出的收益
    int translation_buy = min_buy + 1; // 卖出的收益

    // 不操作，手中无神秘石
    int max_no, min_no; // 用来保存不卖出的结果
    this->f_0(i + 1, max_no, min_no);
    int income_no = max_no; // 保存不卖出的收益
    int translation_no = min_no; // 保存不卖出的收益

    if (income_buy > income_no) {
        /* 买入收益更高 */
        max = income_buy;
        min = translation_buy;
    } else if (income_buy < income_no) {
        /* 不买入收益更高 */
        max = income_no;
        min = translation_no;
    } else {
        /* 收益持平 */
        max = income_buy;
        min = translation_buy <= translation_no ? translation_buy : translation_no; // 交易次数选最小
    }
}

int main(int argc, char* argv[])
{
    vector<int> data;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }

    Solution s(data);

    cout << s << endl;
    return 0;
}
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXSIZE = 1000;
class Solution {
private:
    int out;
    int map[MAXSIZE][MAXSIZE];
    int man_number;
    int woman_number;

public:
    Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman);
    ~Solution();
    friend ostream& operator<<(ostream& os, const Solution& s);
    int translate2Matrix(const vector<vector<int>>& man, const vector<vector<int>>& woman);
};

Solution::Solution(const vector<vector<int>>& man, const vector<vector<int>>& woman)
    : man_number(man.size())
    , woman_number(woman.size())
{
    memset(this->map, 0, sizeof(this->map));
    int all = translate2Matrix(man, woman);
    // vector<bool> isMeetMan(this->man_number, false);
    // vector<bool> isMeetWoman(this->woman_number, false);
    int count = 0;
    while (count < all) {
        for (size_t i = 0; i < this->man_number; i++) {
            int pos = 0;
            for (size_t j = 1; j < this->woman_number; j++) {
                if (this->map[i][j] == 2) {
                    pos = j;
                    break;
                }
                if (this->map[i][j] == 1) {
                    pos = j;
                }
            }
            count+= map[i][pos];
            if (map[i][pos] == 2) {
                // isMeetMan[i] = true;
                // isMeetWoman[pos] = true;
                map[i][pos]-=2;
                for(const int& k : man[i]) {
                    map[i][k]--;
                }
                for (const int& k : woman[pos]) {
                    map[k][pos]--;
                }
                
            }
            if (map[i][pos] == 1) {
                map[i][pos]--;
                if (find(man[i].cbegin(), man[i].cend(), pos) != man[i].cend()) {
                //     isMeetWoman[pos] = false;
                    for(const int& k : man[i]) {
                        map[i][k]--;
                    }
                } else {
                //     isMeetWoman[pos] = true;
                    for(const int &k : woman[pos]) {
                        map[k][pos]--;
                    }
                }
            }
            this->out++;
        }
        
    }
    
}

Solution::~Solution()
{
}

ostream& operator<<(ostream& os, const Solution& s)
{
    os << s.out;
    return os;
}

int Solution::translate2Matrix(const vector<vector<int>>& man, const vector<vector<int>>& woman)
{
    int count = 0;
    for (size_t i = 0, e_i = man.size(); i < e_i; ++i) {
        if (man[i].size() == 0) {
            continue;
        }
        count++;
        for (size_t j = 0, e_j = man[i].size(); j < e_j; ++j) {
            this->map[i][man[i][j]]++;
        }
    }

    for (size_t i = 0, e_i = woman.size(); i < e_i; ++i) {
        if (woman[i].size() == 0) {
            continue;
        }
        count++;
        for (size_t j = 0, e_j = woman[i].size(); j < e_j; ++j) {
            this->map[woman[i][j]][i]++;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> man(n);
    for (size_t i = 0; i < n; i++) {
        int k;
        cin >> k;
        man[i].resize(k, 0);
        for (size_t j = 0; j < k; j++) {
            cin >> man[i][j];
            man[i][j]--;
        }
    }

    vector<vector<int>> woman(m);
    for (size_t i = 0; i < m; i++) {
        int k;
        cin >> k;
        woman[i].resize(k, 0);
        for (size_t j = 0; j < k; j++) {
            cin >> woman[i][j];
            woman[i][j]--;
        }
    }

    Solution s(man, woman);

    cout << s << endl;
    return 0;
}
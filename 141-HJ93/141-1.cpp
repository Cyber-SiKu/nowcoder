#include <iostream>
#include <vector>

using namespace std;

bool getValue(vector<int> data, int value)
{
    if (data.size() == 1) {
        return data[0] == value;
    }

    int tmp = *data.rbegin();
    data.pop_back();
    return getValue(data, value - tmp) || getValue(data, value + tmp);
}

bool isEqua(vector<int> data)
{
    int first_sum = 0;
    int second_sum = 0;
    vector<int> last;
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] % 5 == 0) {
            first_sum += data[i];
        } else if (data[i] % 3 == 0) {
            second_sum += data[i];
        } else {
            last.push_back(data[i]);
        }
    }
    return getValue(last, second_sum - first_sum);
}

int main()
{
    int n;
    while (cin >> n) {
        vector<int> data(n);
        for (size_t i = 0; i < n; i++) {
            cin >> data[i];
        }

        if (isEqua(data)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <regex>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    string input;
    unordered_map<char, pair<int, int>> char2move;
    char2move['A'] = make_pair(-1, 0);
    char2move['D'] = make_pair(1, 0);
    char2move['W'] = make_pair(0, 1);
    char2move['S'] = make_pair(0, -1);

    while (cin >> input)
    {
        pair<int, int> location(0, 0);
        regex split(";");
        vector<string> moves(sregex_token_iterator(input.begin(), input.end(), split, -1), sregex_token_iterator());
        for (string i : moves)
        {
            regex legalMove("[ADWS]\\d{1,2}");
            if (regex_match(i, legalMove) == true)
            {
                pair<int, int> movexy = char2move[i[0]];
                int step = stoi(string(i.begin() + 1, i.end()));
                movexy.first *= step;
                movexy.second *= step;
                location.first += movexy.first;
                location.second += movexy.second;
            }
        }

        cout << location.first << "," << location.second << endl;
    }

    return 0;
}
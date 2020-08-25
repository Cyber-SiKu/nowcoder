#include <bits/stdc++.h>

using namespace std;

class SortString
{
public:
    vector<string> sortStrings(vector<string> str, int n)
    {
        // write code here
        auto compareFunction = [](string a, string b) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a < b;
        };
        map<string, vector<string>, decltype(compareFunction)> str2strs(compareFunction);
        for (string i : str)
        {
            str2strs[i].push_back(i);
        }
        vector<string> ret;
        for (auto i = str2strs.begin(); i != str2strs.end(); ++i)
        {
            ret.push_back(*min_element(i->second.begin(), i->second.end()));
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    vector<string> data{
        " emmaldzsvjggzfoda ", " skmjhsm ", " zjwmkgufsvwrwyvrhk ", " vyksgrwwjmwrhzfvuk ", " wfszrykvjrmuwhkvgw ", " kwrwuwjvksyvhmrzfg ", " kom ", " mko ", " mko ", " nezrxmdjgjqexmqz ", " gjmqdrzqzjeemxxn ", " qqxedgjjmrznmxez ", " xxgmjezerjnqmzdq ", " vwcmmngdsvzx ", " xvmdvwscgnmz ", " msnvvczxdgwm ", " izmvzrhltsiubcukc ", " cslnzuenr ", " rznulsenc ", " lnsnucrez ", " gkyfvvni ", " gikvvynf ", " ivkfyvng ", " vygfvikn ", " nwxkeyhnvniquhpapw ", " wnhyknvanhepwquxip ", " rrpujexoukmmrnmpdzcf ", " ksirghrnjx ", " ixrhgkrnjs ", " kup ", " kpu ", " kpu ", " emnetqjwnfwi ", " qpozvklf ", " qpvkolfz ", " flpkvoqz ", " zlkpvfoq ", " zldjqciktnevrkb ", " vklqjdrktcebizn ", " ntrqkvebiljczkd ", " nkktcebjirqvldz ", " mytegbucud ", " gbtcyuemud ", " gctmuedybu ", " ahgeomesgcehvk ", " oamshhecevggek ", " gmcekevoehsahg ", " gvgeacmheeoksh ", " ma ", " am ", " am ", " wxdyddyrenzsylfwx ", " syedwdylxrwfyxzdn ", " dwsddyelxywrxyfnz ", " rdrrfuowxukryfmli ", " qdjzmdobajs ", " ymysuotfxpboc ", " awzccscrkozbhygrkvv ", " ovrgybhswrczzkcacvk ", " zcrwkyhrzkgacvsocbv ", " vzwgzosrkvkcrcybahc ", " ftytv ", " ttvyf ", " tfyvt ", " vtytf ", " pggunxuyduy ", " qijygauutkt ", " aytqutkugji ", " itjutqugaky ", " nfoenumvnmannkkhmueo ", " ounmkhknefvemnmannou ", " eonmenfkhmuaonnnumvk ", " mvnouemekonfamnnnhku ", " a "};
    vector<string> output = SortString().sortStrings(data, data.size());
    for (string i : output)
    {
        cout << i << endl;
    }

    return 0;
}
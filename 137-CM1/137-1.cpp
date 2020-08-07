class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        set<char> s;
        bool ret = true;
        for(const char &i:iniString) {
            if(s.find(i) != s.end()){
                ret = false;
                break;
            } else{
                s.insert(i);
            }
        }
        return ret;
    }
};
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        sort(stringA.begin(), stringA.end());
        sort(stringB.begin(), stringB.end());
        return stringA == stringB;
    }
};
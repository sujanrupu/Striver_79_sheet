class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length() + b.length();
        string s = a;
        int ans = 1;
        while(a.length() <= 10000) {
            if(a.find(b)!=-1)   return ans;
            a += s;
            ans++;
        }
        return -1;
    }
};

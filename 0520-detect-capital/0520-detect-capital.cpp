class Solution {
public:
    bool detectCapitalUse(string a) {
        int x = 0;
        for (char c : a) {
            if (isupper(c))
                x++;
        }
        if (x == a.size()) return true;
        if (x == 0) return true;
        if (x == 1 && isupper(a[0])) return true; 

        return false;
    }
};
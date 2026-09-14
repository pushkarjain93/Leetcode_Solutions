class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        int x1 = a[0];
        int y1 = a[1];
        int x2 = a[2];
        int y2 = a[3];

        int c1 = b[0];
        int d1 = b[1];
        int c2 = b[2];
        int d2 = b[3];

       if(x1<c2 && c1<x2 && y1<d2 && d1<y2)return true;
       return false;
    }
};
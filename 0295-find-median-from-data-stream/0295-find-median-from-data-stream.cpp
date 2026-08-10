class MedianFinder {
public:
        priority_queue<int,vector<int>,greater<>>mn;
        priority_queue<int>mx;
    MedianFinder() {
    }
    
    void addNum(int a) {
        mx.push(a);
    }
    void norm(){
        int ss = mx.size()+mn.size();
        if(ss%2){
         while((mx.size()-mn.size())!=1){
             mn.push(mx.top());mx.pop();
        }
        }
        else{
          while((mx.size()-mn.size())!=0){
             mn.push(mx.top());mx.pop();
         }
        }
        if(mn.size()>0){
            while(mx.top()>mn.top()){
                int x = mx.top();int y=mn.top();
                mx.pop();mn.pop();
                mx.push(y);
                mn.push(x);
            }
        }
    }
    double findMedian() {
        double ans;
        norm();
          int s = mx.size()+mn.size();
          if(s%2){
             ans=mx.top();
          }
          else{
            ans = (mx.top()+mn.top())/2.0;
          }
          return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// LEETCODE - 901 Online Stock Span


// BRUTE FORCE APPROACH
// TC : O(n^2)
// SC : O(n)
class StockSpanner {
public:
    vector <int> arr;
    
    int next(int price) {
        arr.push_back(price);
        int span = 1;
        for (int i=arr.size()-2; i>=0; i--){
            if (arr[i] > price) break;
            span++;
        }
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



// OPTIMAL APPROACH
// TC : O(2n) = O(n)
 // SC : O(2n) = O(n)
 class StockSpanner {
public:
    int i = 0;
    stack <pair<int, int>> s;

    int next(int price) {
        while (!s.empty() && s.top().second <= price){
            s.pop();
        }
        int span = s.empty() ? i-(-1) : i-s.top().first;
        s.push({i++, price});
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 
class StockSpanner {
public:
    stack <pair<int, int>> s;

    int next(int price) {
        int span = 1;
        while (!s.empty() && s.top().first <= price){
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
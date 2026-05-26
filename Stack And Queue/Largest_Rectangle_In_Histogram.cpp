// LEETCODE - 84. Largest Rectangle in Histogram

// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largestRectangleArea = 0;
        for (int i=0; i<n; i++){
            int NSL = -1;
            for (int j=i-1; j>=0; j--){
                if (heights[j] < heights[i]) {
                    NSL = j;
                    break;
                }
            }
            int NSR = n;
            for (int k=i+1; k<n; k++){
                if (heights[k] < heights[i]) {
                    NSR = k;
                    break;
                }
            }
            int area = heights[i] * (NSR-NSL-1);
            largestRectangleArea = max(largestRectangleArea, area);
        }
        return largestRectangleArea;
    }
};


// BETTER APPROACH
// TC : O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    vector<int> findNSL(vector<int>& heights){
        int n = heights.size();
        vector<int> NSL(n);
        stack<int> s;
        for (int i=0; i<n; i++){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            NSL[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        return NSL;
    }

    vector<int> findNSR(vector<int>& heights){
        int n = heights.size();
        vector<int> NSR(n);
        stack<int> s;
        for (int i=n-1; i>=0; i--){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            NSR[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        return NSR;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> NSL = findNSL(heights);
        vector <int> NSR = findNSR(heights);
        int largestRectangleArea = 0;
        for (int i=0; i<n; i++){
            int area = heights[i] * (NSR[i]-NSL[i]-1);
            largestRectangleArea = max(largestRectangleArea, area);
        }
        return largestRectangleArea;
    }
};


// OTPIMIZED APPROACH
// TC : O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> s;
        int largestRectangleArea = 0;
        for (int i=0; i<n; i++){
            while (!s.empty() && heights[s.top()] > heights[i]){
                int index = s.top();
                s.pop();
                int NSL = !s.empty() ? s.top() : -1;
                int NSR = i;
                int area = heights[index]*(NSR-NSL-1);
                largestRectangleArea = max(largestRectangleArea, area);
            }
            s.push(i);
        }
        while (!s.empty()){
            int index = s.top();
            s.pop();
            int NSR = n;
            int NSL = !s.empty() ? s.top() : -1;
            int area = heights[index]*(NSR-NSL-1) ;
            largestRectangleArea = max(largestRectangleArea, area);
        }
        return largestRectangleArea;
    }
};
LEETCODE - 85. Maximal Rectangle

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        // TC : O(rows * cols)
        // AS : O(cols)
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maximalRectangleArea = 0;
        vector <int> height(cols, 0);
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (matrix[i][j] == '1'){
                    height[j] += 1;
                }else {
                    height[j] = 0;
                }
            }
            maximalRectangleArea = max(maximalRectangleArea, largestRectangleArea(height));
        }
        return maximalRectangleArea;
    }
};
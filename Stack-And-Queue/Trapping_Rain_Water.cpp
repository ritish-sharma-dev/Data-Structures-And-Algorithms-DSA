LEETCODE - 42. Trapping Rain Water


// TC : O(n)
// AS : O(n)
class Solution {
public:
    vector<int> findLGL(vector<int>& height) {
        int n = height.size();
        vector<int> LGL(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                LGL[i] = -1;
                s.push(i);
            } else {
                LGL[i] = height[s.top()] > height[i] ? s.top() : -1;
            }
            if (!s.empty() && height[i] > height[s.top()]) {
                s.push(i);
            }
        }
        return LGL;
    }

    vector<int> findLGR(vector<int>& height) {
        int n = height.size();
        vector<int> LGR(n, 0);
        stack<int> s;
        for (int i=n-1; i>=0; i--) {
            if (s.empty()) {
                LGR[i] = n;
                s.push(i);
            } else {
                LGR[i] = height[s.top()] > height[i] ? s.top() : n;
            }
            if (!s.empty() && height[i] > height[s.top()]) {
                s.push(i);
            }
        }
        return LGR;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> LGL = findLGL(height);
        vector<int> LGR = findLGR(height);
        int totalTrap = 0;
        for (int i=0; i<n; i++){
            if (LGL[i] != -1 && LGR[i] != n){
                int t = min(height[LGL[i]], height[LGR[i]]) - height[i];
                totalTrap += t;
            }
        }
        return totalTrap;
    }
};




// TC : O(n)
// AS : O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxIndex = 0;
        for (int i=0; i<n; i++){
            if (height[i] > height[maxIndex]){
                maxIndex = i;
            }
        }
        int maxValue = height[maxIndex];
        int totalTrap = 0;
        int leftMax = 0;
        int rightMax = maxValue;
        for (int j=0; j<maxIndex; j++){
            if (leftMax > height[j]) {
                totalTrap += leftMax - height[j];
            }
            leftMax = max(leftMax, height[j]);
        }

        leftMax = maxValue;
        rightMax = 0;
        for (int k=n-1; k>maxIndex; k--){
            if (rightMax > height[k]){
                totalTrap += rightMax - height[k];
            }
            rightMax = max(rightMax, height[k]);
        }
        return totalTrap; 
    }
};
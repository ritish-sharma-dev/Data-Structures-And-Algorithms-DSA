// LEETCODE - 1423. Maximum Points You Can Obtain from Cards


// BETTER APPROACH - SLIDING WINDOW
// TC : O(n)
// AS : O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = INT_MIN;

        vector <int> x = cardPoints;
        x.insert(x.end(), cardPoints.begin(), cardPoints.end());

        int i = n-k, j = n-1, score = 0;
        for (int l=i; l<=j; l++){
            score += x[l];
        }

        while (j < n+k){
            maxScore = max(score, maxScore);
            j++;
            if (j >= n+k) break;
            score += x[j];
            score -= x[i];
            i++;
        }

        return maxScore;
    }
};


// OPTIMAL APPROACH
// TC : O(k)
// AS : O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = INT_MIN;

        int i = 0, j = k-1, score = 0;
        for (int l=0; l<k; l++){
            score += cardPoints[l];
        }

        int count = 0;
        while (count < k+1){
            maxScore = max(score, maxScore);
            i--;
            if (i < 0) i = n-1;
            score += cardPoints[i];
            score -= cardPoints[j];
            j--;
            if (j < 0) j = n-1;
            count++;
        }

        return maxScore;
    }
};
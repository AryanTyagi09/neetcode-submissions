class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            // process until stack is valid
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();

                int height = heights[index];
                int width;

                if(st.empty()) {
                    width = i;   // from 0 to i-1
                } else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        // process remaining stack
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            int height = heights[index];
            int width;

            if(st.empty()) {
                width = n;
            } else {
                width = n - st.top() - 1;
            }

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
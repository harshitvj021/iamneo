#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> s;
    
    for (int i=0;i<n;i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() +1;
        s.push(i);
    }
    while (!s.empty()) {
        s.pop();
    }
    for( int i=n -1; i>=0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }
    int maxArea = 0;
    for (int i =0; i< n; i++) {
        int width = right[i] - left[i] + 1;
        int area = width * heights [i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
     
    vector<int> heights(n);
    for (int i = 0; i<n; i++) {
        cin >> heights[i];
    }
    
    int result = largestRectangleArea(heights);
    cout << result << endl;
    
    return 0;
}

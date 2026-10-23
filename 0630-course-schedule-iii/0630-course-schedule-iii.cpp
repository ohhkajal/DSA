class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;
        int time = 0;

        for (auto& course : courses) {
            time += course[0];
            pq.push(course[0]);

            if (time > course[1]) {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
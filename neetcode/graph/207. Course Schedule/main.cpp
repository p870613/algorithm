class Solution {
public:
    bool dfs(int course, unordered_map<int, vector<int>> &m, unordered_set<int> &v) {
        if (v.find(course) != v.end())
            return false;
        if (m[course].empty())
            return true;
        
        v.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            if (!dfs(m[course][i], m, v))
                return false;
        }
        m[course].clear();
        v.erase(course);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> visit;

        for (int i = 0; i < prerequisites.size(); i++)
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, m, visit)) {
                return false;
            }
        }
        return true;
    }
};

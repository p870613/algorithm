class Solution {
public:
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visit,
        unordered_set<int>& cycle, vector<int>& result) {
        
        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        if (visit.find(course) != visit.end()) {
            return true;
        }
        cycle.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            int nextCourse = m[course][i];
            if (!dfs(nextCourse, m, visit, cycle, result)) {
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        result.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;

        for(int i = 0; i < prerequisites.size(); i++)
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        unordered_set<int> cycle;
        unordered_set<int> visit;
        vector<int> result;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, m, visit, cycle, result)) {
                return {};
            }
        }
        return result;
        
    }
};

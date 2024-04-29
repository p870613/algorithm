class Solution {
public:
    int get_value(int index, vector<vector<int>>m) {
        int row = m[0].size();
        return m[index/row][index % row];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;

        while (r >= l) {
            int m = (l + r) / 2;
            int cur_val = get_value(m, matrix);
            if(target == cur_val)
                return true;
            else if(target > cur_val)
                l = m + 1;
            else
                r = m - 1;
                
        }
        return false;
    }
};

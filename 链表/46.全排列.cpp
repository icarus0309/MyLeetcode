/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int> nums, int len, int depth, vector<int>& path,
             vector<bool>& used, vector<vector<int>>& res) {
        if (depth == len) {
            res.push_back(path);
            return;
        }

        // 在非叶子结点处，产生不同的分支，这一操作的语义是：在还未选择的数中依次选择一个元素作为下一个位置的元素，这显然得通过一个循环实现。
        for(int i = 0; i < len; i++) {
            if (!used[i]) {
                path[i] = nums[i];
                used[i] = true;

                dfs(nums, len, depth + 1, path, used, res);
                // 注意：下面这两行代码发生 「回溯」，回溯发生在从 深层结点 回到 浅层结点 的过程，代码在形式上和递归之前是对称的
                used[i] = false;
                path[i] = 0;
            }
        }
    } 

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();;
        if (0 == len) {
            return res;
        }
        vector<bool> used(n, false);
        vector<int> path(n, 0);
        dfs(nums, len, 0, path, used, res);
        return res;
    }
};
// @lc code=end


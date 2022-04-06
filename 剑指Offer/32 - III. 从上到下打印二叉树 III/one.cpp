/*
 * @Author: your name
 * @Date: 2022-04-05 23:22:09
 * @LastEditTime: 2022-04-05 23:24:38
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/32 - III. 从上到下打印二叉树 III/one.cpp
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]

提示：
节点总数 <= 1000
*/

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (nullptr == root) {
            return res;
        }
        int n = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> tmp;
            n++;
            for (int i = que.size(); i > 0; i--) {
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = NULL;
    Solution *Obj = new Solution;
    Obj->levelOrder(root);
    return 0;
}
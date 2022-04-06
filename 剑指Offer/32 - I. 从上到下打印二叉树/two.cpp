/*
 * @Author: your name
 * @Date: 2022-04-05 22:22:32
 * @LastEditTime: 2022-04-05 23:04:13
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/32 - I. 从上到下打印二叉树/two.cpp
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]

提示：
节点总数 <= 1000
*/
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        if (nullptr == root) {
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
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
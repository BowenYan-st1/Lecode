/*
 * @Author: your name
 * @Date: 2022-04-09 21:26:42
 * @LastEditTime: 2022-04-09 21:40:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/27. 二叉树的镜像/one.cc
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

限制：
0 <= 节点个数 <= 1000
*/

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
    TreeNode *mirrorTree(TreeNode *root)
    {
        isSubStructure(root);
        return root;
    }

private:
    bool isSubStructure(TreeNode *root)
    {
        if (nullptr == root) {
            return true;
        }
        struct TreeNode *tmp = nullptr;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        isSubStructure(root->left);
        isSubStructure(root->right);
        return true;
    }
};

int main(int argc, char **argv)
{
    TreeNode *A = nullptr;
    Solution *Obj = new Solution;
    Obj->mirrorTree(A);
    return 0;
}
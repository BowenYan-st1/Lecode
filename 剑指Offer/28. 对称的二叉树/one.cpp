/*
 * @Author: your name
 * @Date: 2022-04-09 21:45:37
 * @LastEditTime: 2022-04-09 22:10:45
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/28. 对称的二叉树/one.cpp
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false

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
    bool isSymmetric(TreeNode *root)
    {
        if (nullptr == root) {
            return true;
        }
        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode *right, TreeNode *left)
    {
        if (nullptr == right && nullptr == left) {
            return true;
        }
        if (right == nullptr || left == nullptr ||
            right->val != left->val) {
            return false;
        }
        return compare(right->right, left->left) &&
               compare(right->left, left->right);
    }
};

int main(int argc, char **argv)
{
    TreeNode *A = nullptr;
    Solution *Obj = new Solution;
    Obj->isSymmetric(A);
    return 0;
}

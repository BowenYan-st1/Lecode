/*
 * @Author: your name
 * @Date: 2022-04-09 21:05:21
 * @LastEditTime: 2022-04-09 21:22:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/26. 树的子结构/one.cpp
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (nullptr == A || nullptr == B) {
            return false;
        }
        return (recur(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

private:
    bool recur(TreeNode *A, TreeNode *B)
    {
        if (nullptr == B) {
            return true;
        }
        if (nullptr == A) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return (recur(A->left, B->left) && recur(A->right, B->right));
    }
};

int main(int argc, char **argv)
{
    TreeNode *A = nullptr, *B = nullptr;
    Solution *Obj = new Solution;
    Obj->isSubStructure(A, B);
    return 0;
}
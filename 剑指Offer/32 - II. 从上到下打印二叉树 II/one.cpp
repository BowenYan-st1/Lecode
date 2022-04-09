/*
 * @Author: your name
 * @Date: 2022-04-05 23:01:49
 * @LastEditTime: 2022-04-09 20:58:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/32 - II. 从上到下打印二叉树 II/one.cpp
 */
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
  [9,20],
  [15,7]
]

提示：
节点总数 <= 1000
*/
/* Definition for a binary tree node. */
struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

#if 1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> deque;
        vector<vector<int>> res;
        if(root != NULL) deque.push_back(root);
        while(!deque.empty()) {
            // 打印奇数层
            vector<int> tmp;
            for(int i = deque.size(); i > 0; i--) {
                // 从左向右打印
                TreeNode* node = deque.front();
                deque.pop_front();
                tmp.push_back(node->val);
                // 先左后右加入下层节点
                if(node->left != NULL) deque.push_back(node->left);
                if(node->right != NULL) deque.push_back(node->right);
            }
            res.push_back(tmp);
            if(deque.empty()) break; // 若为空则提前跳出
            // 打印偶数层
            tmp.clear();
            for(int i = deque.size(); i > 0; i--) {
                // 从右向左打印
                TreeNode* node = deque.back();
                deque.pop_back();
                tmp.push_back(node->val);
                // 先右后左加入下层节点
                if(node->right != NULL) deque.push_front(node->right);
                if(node->left != NULL) deque.push_front(node->left);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
#else
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != NULL) que.push(root);
        while(!que.empty()) {
            vector<int> tmp;
            for(int i = que.size(); i > 0; i--) {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
            if(res.size() % 2 == 1) reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};
#endif

int main(int argc, char **argv)
{
    TreeNode *root = NULL;
    Solution *Obj = new Solution;
    Obj->levelOrder(root);
    return 0;
}
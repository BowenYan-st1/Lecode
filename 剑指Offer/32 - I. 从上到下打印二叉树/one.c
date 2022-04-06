/*
 * @Author: your name
 * @Date: 2022-04-05 20:28:50
 * @LastEditTime: 2022-04-05 22:11:44
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/32 - I. 从上到下打印二叉树/one.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

/* Definition for a binary tree node. */
struct TreeNode
{
    int              val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *levelOrder(struct TreeNode *root, int *returnSize)
{
    if (NULL == root || NULL == returnSize) {
        return NULL;
    }
    int cnt = 0;
    char *str = NULL;
    return str;
}

int main(int atgc, char **argv)
{
    return 0;
}

/*
 * @Author: your name
 * @Date: 2022-04-04 16:26:51
 * @LastEditTime: 2022-04-04 17:04:36
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/04. 二维数组中的查找/one.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
在一个 n * m
的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

限制：
0 <= n <= 1000
0 <= m <= 1000
*/

/*
 * 输入 **matrix 是长度为 matrixSize 的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *matrixColSize 数组作为另一输入，*matrixColSize 数组的长度也为 matrixSize
 */
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if (matrix == NULL || matrixSize <= 0 || matrixColSize <= 0) {
        return false;
    }
    for (int i = 0, j = *matrixColSize - 1; i < matrixSize && j >= 0;) {
        if (matrix[i][j] > target) {
            j--;
        } else if (matrix[i][j] < target) {
            i++;
        } else {
            return true;
        }
    }
    return false;
}


int main(int argc, char **argv)
{
    int nums[5][5] =   {
        1,   4,  7, 11, 15,
        2,   5,  8, 12, 19,
        3,   6,  9, 16, 22,
        10, 13, 14, 17, 24,
        18, 21, 23, 26, 30,
    };
    int *p_nums = nums[0];
    int **pp_nums = &p_nums;
    int col = sizeof(nums)/sizeof(nums[0]);
    printf("result = %d\n", findNumberIn2DArray(pp_nums, sizeof(nums[0])/sizeof(int), &col, 5));
    return 0;
}

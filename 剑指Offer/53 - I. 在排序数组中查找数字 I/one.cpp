/*
 * @Author: your name
 * @Date: 2022-04-02 21:44:56
 * @LastEditTime: 2022-04-04 15:45:21
 * @LastEditors: Please set LastEditors
 * @Description:
 *          输入: nums = [5,7,7,8,8,10], target = 8
 *          输出: 2
 * @FilePath: /剑指Offer/53 - I. 在排序数组中查找数字 I/one.cpp
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {}
};

int main(int argc, char **argv)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution   *Obj = new Solution;
    printf("%d\n", Obj->search(nums, 2));
    return 0;
}
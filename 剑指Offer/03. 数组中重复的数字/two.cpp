/*
 * @Author: unkonw
 * @Date: 2022-04-01 20:17:54
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-04-02 21:38:44
 * @FilePath: /剑指Offer/03. 数组中重复的数字/two.cpp
 * @Description:
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, bool> map;
        for (int num : nums) {
            if (map[num]) {
                return num;
            }
            map[num] = true;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums = {1, 2, 3, 2, 1};
    Solution *Obj = new Solution;
    printf("%d\n", Obj->findRepeatNumber(nums));
    return 0;
}
/*
 * @Author: unkonw
 * @Date: 2022-04-11 09:30:27
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-04-11 10:22:00
 * @FilePath: /剑指Offer/10- I. 斐波那契数列/one.cpp
 * @Description:
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即
F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5

提示：
0 <= n <= 100
*/

using namespace std;

class Solution {
public:
    int fib(int n)
    {
        int a = 0, b = 1, sum;
        for (int i = 0; i < n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};

int main(int argc, char **argv)
{
    Solution *Obj = new Solution;
    int       n = atoi(argv[1]);
    cout << "fib(" << n << ")=" << Obj->fib(n) << endl;
    return 0;
}

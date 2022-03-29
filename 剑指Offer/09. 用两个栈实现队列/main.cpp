/*
 * @Author: unkonw
 * @Date: 2022-03-29 15:05:52
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-03-29 16:10:54
 * @FilePath: /剑指Offer/09. 用两个栈实现队列/main.cpp
 * @Description: 剑指Offer/09. 用两个栈实现队列
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */
#include <stack>
#include <iostream>
#include <stdio.h>
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

class CQueue {
  public:
    stack<int> A, B;
    CQueue() {}

    void appendTail(int value)
    {
        A.push(value);
    }

    int deleteHead()
    {
        int tmp = 0;
        if (!B.empty()) {
            tmp = B.top();
            B.pop();
            return tmp;
        }
        if (A.empty()) {
            return -1;
        }
        while (!A.empty()) {
            tmp = A.top();
            B.push(tmp);
            A.pop();
        }
        tmp = B.top();
        B.pop();
        return tmp;
    }
};

int main(int argc, char** argv)
{
    CQueue* obj = new CQueue();
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    return true;
}

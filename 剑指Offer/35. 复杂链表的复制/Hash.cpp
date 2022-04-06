/*
 * @Author: unkonw
 * @Date: 2022-03-31 10:47:27
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-03-31 11:09:11
 * @FilePath: /剑指Offer/35. 复杂链表的复制/Hash.cpp
 * @Description:
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <unordered_map>

class Node {
  public:
    int   val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val    = _val;
        next   = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
            return nullptr;
        Node*                            cur = head;
        std::unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur      = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while (cur != nullptr) {
            map[cur]->next   = map[cur->next];
            map[cur]->random = map[cur->random];
            cur              = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
};

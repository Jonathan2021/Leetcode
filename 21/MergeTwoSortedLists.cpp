/*
 * =====================================================================================
 *
 *       Filename:  MergeTwoSortedLists.cpp
 *
 *    Description: https://leetcode.com/problems/merge-two-sorted-lists/ 
 *
 *        Version:  1.0
 *        Created:  07/15/20 17:04:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode base;
    ListNode *ptr = &base;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            ptr->next = l1;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = l1 ? l1 : l2;
    return base.next;
}

void printList(ListNode *node)
{
    for(; node; node = node->next)
    {
        std::cout << node->val << " -> ";
    }
    std::cout << std::endl;
}

int main(void)
{
    ListNode l1_4(4);
    ListNode l1_2(2, &l1_4);
    ListNode l1_1(1, &l1_2);
    ListNode l2_4(4);
    ListNode l2_3(3, &l2_4);
    ListNode l2_1(1, &l2_3);

    auto merged = mergeTwoLists(&l1_1, &l2_1);
    printList(merged);
    return 0;
}

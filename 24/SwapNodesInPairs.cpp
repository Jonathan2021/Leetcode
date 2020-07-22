/*
 * =====================================================================================
 *
 *       Filename:  SwapNodesInPairs.cpp
 *
 *    Description: https://leetcode.com/problems/swap-nodes-in-pairs/ 
 *
 *        Version:  1.0
 *        Created:  07/21/20 12:43:45
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

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *new_head = head->next;
    head->next = swapPairs(new_head->next);
    new_head->next = head;
    return new_head;
}

void printLinkedList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next)
            std::cout << " -> ";
        head = head->next;
    }
}

int main(void)
{
    ListNode four(4);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);
    printLinkedList(swapPairs(&one));
    return 0;
}

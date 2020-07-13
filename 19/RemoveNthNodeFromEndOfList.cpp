/*
 * =====================================================================================
 *
 *       Filename:  RemoveNthNodeFromEndOfList.cpp
 *
 *    Description: https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 
 *
 *        Version:  1.0
 *        Created:  13/07/2020 15:00:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    std::vector<ListNode *> nodes;
    for (; head; head = head->next)
    {
        nodes.push_back(head);
    }
    int index_remove = nodes.size() - n;
    if (!index_remove)
        return (nodes.size() == 1) ? nullptr : nodes[1];
    nodes[index_remove - 1]->next = nodes[index_remove]->next;
    return nodes[0];
}

int main(void)
{
    ListNode five(5);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);
    ListNode *head = removeNthFromEnd(&four, 1);
    while (head)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    return 0;
}

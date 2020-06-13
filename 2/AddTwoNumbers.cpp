/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumbers.cpp
 *
 *    Description: https://leetcode.com/problems/add-two-numbers/ 
 *
 *        Version:  1.0
 *        Created:  13/06/2020 12:11:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
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

ListNode *addTwoNumbersRec(ListNode *l1, ListNode *l2, int rest)
{
    if (!l1 && !l2 && !rest)
        return nullptr;
    int val1 = (l1) ? l1->val : 0;
    int val2 = (l2) ? l2->val : 0;
    int sum = val1 + val2 + rest;
    return new ListNode(sum % 10,
            addTwoNumbersRec((l1) ? l1->next : l1, (l2) ? l2->next : l2,
                sum / 10)
            );
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return addTwoNumbersRec(l1, l2, 0);
}

void print(ListNode *num)
{
    if (!num)
        return;
    print(num->next);
    std::cout << num->val;
}

int main(void)
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    print(addTwoNumbers(l1, l2));
}

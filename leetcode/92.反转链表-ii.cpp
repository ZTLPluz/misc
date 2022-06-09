/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 private:
  void reverseLinkedList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;

    ListNode *pre = dummy_head;

    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    ListNode *right_node = pre;
    for (int i = 0; i < right - left + 1; i++) {
      right_node = right_node->next;
    }

    ListNode *left_node = pre->next;
    ListNode *curr = right_node->next;

    pre->next = nullptr;
    right_node->next = nullptr;

    reverseLinkedList(left_node);

    pre->next = right_node;
    left_node->next = curr;
    return dummy_head->next;
  }
};
// @lc code=end

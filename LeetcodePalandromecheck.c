#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }

   
    char str[100000]; 
    int len = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        str[len++] = temp->val; 
        temp = temp->next;
    }

   
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false; 
        }
    }

    return true; 
}

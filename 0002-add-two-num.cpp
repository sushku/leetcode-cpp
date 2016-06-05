#include <iostream>
#include <vector>
#include "common.hpp"

using namespace std;

extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0, carry = 0;
    ListNode* head = NULL;
    ListNode* prev = NULL;
    while(l1 != NULL || l2 != NULL) {
        sum = 0;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        if(sum >= 10) {
            sum = sum % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ListNode* node = new ListNode(sum);
        if(!head) {
            head = node;
        }
        else {
            prev->next = node;
        }
        prev = node;
    }
    if(carry) {
        prev->next = new ListNode(carry);
    }
    return head;
}

int main(int argc, char * argv[]) {
    int arr1[] = {2, 4, 3};
    vector<int> vec1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    int arr2[] = {5, 6, 4};
    vector<int> vec2(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    ListNode* list1 = createLinkedList(vec1);
    ListNode* list2 = createLinkedList(vec2);
    printLinkedList(list1);
    printLinkedList(list2);
    ListNode* sum = addTwoNumbers(list1, list2);
    printLinkedList(sum);
    return 0;
}

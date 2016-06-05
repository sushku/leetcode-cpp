#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include "common.hpp"

ListNode* createLinkedList(std::vector<int> vec) {
    int vsize = vec.size();
    if (vsize == 0) return NULL;
    int i = 0;
    ListNode* list = new ListNode(vec[i]);
    ListNode* prev = list;
    i++;
    while (i < vsize) {
        ListNode* node = new ListNode(vec[i]);
        prev->next = node;
        prev = node;
        i++;
    }
    return list;
}

void printLinkedList(ListNode* list) {
    if (list == NULL) return;
    ListNode* node = list;
    while (node != NULL) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
    return;
}

TreeNode* createBinaryTree(std::vector<std::string> vec) {
    int vsize = vec.size();
    if (vsize == 0) return NULL;
    int i = 0;
    TreeNode* tree = new TreeNode(std::stoi(vec[i]));
    std::queue<TreeNode*> q;
    q.push(tree);
    i++;
    while (i < vsize) {
        int s = q.size();
        while (s > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (vec[i] != "#") {
                TreeNode* left = new TreeNode(std::stoi(vec[i]));
                node->left = left;
                q.push(left);
            }
            i++;
            if (i >= vsize) break;
            if (vec[i] != "#") {
                TreeNode* right = new TreeNode(std::stoi(vec[i]));
                node->right = right;
                q.push(right);
            }
            i++;
            if (i >= vsize) break;
            s--;
        }
    }
    return tree;
}

int findMaxDepth(TreeNode* node) {
    int dl = 0, dr = 0;
    if (node == NULL) return 0;
    dl = findMaxDepth(node->left) + 1;
    dr = findMaxDepth(node->right) + 1;
    return std::max(dl, dr);
}

/*

000000000011111111112222222222333333333344444444445555555555666
012345678901234567890123456789012345678901234567890123456789012

                               100
                 /--------------+--------------\
               101                             102
         /------+------\                 /------+------\
       222             333             222             333
     /--+--\         /--+--\         /--+--\         /--+--\
   444     555     666     777     444     555     666     777
   / \     / \     / \     / \     / \     / \     / \     / \
 888 999 000 111 222 333 444 555 888 999 000 111 222 333 444 555

*/
void printBinaryTree(TreeNode* tree) {
    if (tree == NULL) return;

    int d = findMaxDepth(tree);

    std::queue<TreeNode*> q;
    q.push(tree);

    int offset = std::pow(2, d) - 2;
    std::string spaces = std::string(offset, ' ');
    std::string valStr = "";
    if (tree->val < 10) {
        valStr = " " + std::to_string(tree->val) + " ";
    }
    else if (tree->val < 100) {
        valStr = std::to_string(tree->val) + " ";
    }
    else {
        valStr = std::to_string(tree->val);
    }
    std::cout << spaces << valStr << std::endl;
    d--;

    while (q.size() > 0) {
        int s = q.size();
        std::string symLine = "";
        std::string elemLine = "";
        std::string offsetSpaces = "";
        std::string offsetDashes = "";
        while (s > 0) {
            TreeNode* node = q.front();
            q.pop();
            offset = std::pow(2, d) - 2;
            if (offset != 0) {
                offsetSpaces = std::string(offset, ' ');
                offsetDashes = std::string(offset, '-');
            }
            else {
                offsetSpaces = "";
                offsetDashes = "";
            }
            if (node->left == NULL) {
                symLine += (offsetSpaces + "   " + offsetSpaces);
                elemLine += (offsetSpaces + "   " + offsetSpaces);
            }
            else {
                symLine += offsetSpaces;
                symLine += "  /";
                symLine += offsetDashes;
                elemLine += offsetSpaces;
                if (node->left->val < 10) {
                    valStr = " " + std::to_string(node->left->val) + " ";
                }
                else if (node->left->val < 100) {
                    valStr = std::to_string(node->left->val) + " ";
                }
                else {
                    valStr = std::to_string(node->left->val);
                }
                elemLine += valStr;
                elemLine += offsetSpaces;
                q.push(node->left);
            }
            if (d == 1) 
                symLine += " ";
            else
                symLine += "+";
            elemLine += " ";
            if (node->right == NULL) {
                symLine += (offsetSpaces + "   " + offsetSpaces);
                elemLine += (offsetSpaces + "   " + offsetSpaces);
            }
            else {
                symLine += offsetDashes;
                symLine += "\\  ";
                symLine += offsetSpaces;
                elemLine += offsetSpaces;
                if (node->right->val < 10) {
                    valStr = " " + std::to_string(node->right->val) + " ";
                }
                else if (node->right->val < 100) {
                    valStr = std::to_string(node->right->val) + " ";
                }
                else {
                    valStr = std::to_string(node->right->val);
                }
                elemLine += valStr;
                elemLine += offsetSpaces;
                q.push(node->right);
            }
            symLine += " ";
            elemLine += " ";
            s--;
        }
        d--;
        std::cout << symLine << std::endl;
        std::cout << elemLine << std::endl;
        if (d == 0) break;
    }
    return;
}


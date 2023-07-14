
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    // O(nlogk) - time complexity
    // O(1) - memory complexity
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int n = static_cast<int>(lists.size());
        if (!n || n == 1 && lists.front() == nullptr) return nullptr;
        ListNode* last = nullptr;
        while(n > 1) {
            int cnt = 0;
            for(int i = 0; i < n - 1; i+=2) {
                lists[i] = merge2Lists(lists[i], lists[i + 1]);
                swap(lists[i], lists[cnt]);
                ++cnt;
            }
            swap(lists[n-1], lists[cnt]);
            n = n/2 + n%2;
        }
        return lists.front();
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        start = nullptr;
        if (l1 && l2) {
            if (l1->val < l2->val) {
                start = l1;
                l1 = l1->next;
            } else {
                start = l2;
                l2 = l2->next;
            }
        } else if (l1) { return l1; }
        else if (l2) { return l2; }
        else return nullptr;
        ListNode* cur = start;
        while(true) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    cur = cur->next;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                    l2 = l2->next;
                }
            } else if (l1) {
                cur->next = l1;
                break;
            } else if (l2) {
                cur->next = l2;
                break;
            } else break;
        }
        return start;
    }
    ListNode* start = nullptr;
};
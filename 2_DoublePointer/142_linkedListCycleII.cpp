/*
给定一个链表，返回链表开始入环的第一个节点。
如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。
*/
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i) 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            if(!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }while(slow != fast);
        
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(){
    // find cycle in a linked list:
    // fast and slow pointer
    // if pointerA is faster than pointerB
    // once there is a cycle in linked list
    // this 2 pointer will must point to the same node at same time

    /*
    1、设慢指针为slow，快指针为fast，环的长度为C，入环之前的长度为L
    2、慢指针走L，开始入环（即在环的0节点位置），
       此时fast一共走了2L，减去入环前的L，它在环的位置是t = L%C
       fast距离环的入口位置是C-t
    3、slow再走C-t，fast走了两个C-t，它们相遇
    4、如果可以证明slow再走L步可以到入环的位置，那么就设定一个pos指向链表头节点
       slow、pos同时走，pos走L步到入环位置，二者相遇在入环的位置
    5、因此只需证明4中的假设，即(C-t+L)%C == 0
       很显然2中t = L%C，因此成立。
    */
   return 0;
}
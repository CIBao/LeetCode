/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p, *q;
        p = new ListNode(0);
        q = p;
        int a, b, c;
        while(l1!=NULL ||l2!=NULL||c!=0){
            if(l1!=NULL){
                a=l1->val;
                l1=l1->next;
            }else a = 0;
            if(l2!=NULL){
                b=l2->val;
                l2=l2->next;
            }else b = 0;
            int sum = a+b+c;
            p->next = new ListNode(sum%10);
            c = sum/10;
            p = p->next;
        }
        return q->next;
    }
};

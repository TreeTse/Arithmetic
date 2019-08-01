/*
题目描述：
一种特殊的链表节点类描述如下：
public class Node { 
    public int value; 
    public Node next; 
    public Node rand;
    public Node(int data) { 
        this.value = data; 
    }
}
Node类中的value是节点值，next指针和正常单链表中next指针的意义一样，都指向下一个节点，rand指针是Node类中新增的指针，这个指
针可能指向链表中的任意一个节点，也可能指向null。给定一个由Node节点类型组成的无环单链表的头节点head，请实现一个 函数完成这个
链表中所有结构的复制，并返回复制的新链表的头节点。进阶：不使用额外的数据结构，只用有限几个变量，且在时间复杂度为O(N)内完成原
问题要实现的函数。
*/


//解法一：使用hash_map来解决


struct ListNode {
	int label;
	struct ListNode *next, *random;
	ListNode(int x):
		label(x),next(NULL),random(NULL){}
};


class Solution {
public:
	ListNode* copyListWithRand(ListNode* head) {
		if (head == NULL)
			return NULL;
		hash_map<ListNode*, ListNode*> hashNode;
		ListNode* cur = head;
		while (cur != NULL) {
			hashNode[cur] = new ListNode(cur->label);
			cur = cur->next;
		}
		cur = head;
		while (cur != NULL) {
			hashNode[cur]->next = hashNode[cur->next];
			hashNode[cur]->random = hashNode[cur->random];
			cur = cur->next;
		}
		return hashNode[head];
	};
}



//进阶解法：不需要额外的数据结构，只用有限的几个变量

class Solution {
public:
	ListNode* copyListWithRand(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* cur = head;
		while (cur) {
			ListNode* node = new ListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}
		cur = head;
		while (cur) {
			ListNode* node = cur->next;
			if (cur->random) {
				node->random = cur->random->next;
			}
			cur = node->next;
		}
		//进行拆分
		ListNode* clone = head->next;
		ListNode* tmp;
		cur = head;
		while (cur->next) {
			tmp = cur->next;
			cur->next = tmp->next;
			cur = tmp;
		}
		return clone;
	};
}

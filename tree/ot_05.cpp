/*
题目描述：
现在有一种新的二叉树节点类型如下：
public class Node {
public:
	int value; 
	Node left;
	Node right; 
	Node parent;
	Node(int data) { this.value = data; }
	该结构比普通二叉树节点结构多了一个指向父节点的parent指针。假
	设有一棵Node类型的节点组成的二叉树，树中每个节点的parent指针
	都正确地指向自己的父节点，头节点的parent指向null。只给一个在
	二叉树中的某个节点node，请实现返回node的后继节点的函数。在二
	叉树的中序遍历的序列中,node的下一个节点叫作node的后继节点。
}
*/


Node* getNode(Node* node) {
	if (node == NULL)
		return node;
	Node* cur = node;
	if (node->right) {
		cur = cur->right;
		while (cur->left) {
			cur = cur->left;
		}
		return cur;
	}
	else {
		cur = node->parent;
		while (cur->left != node && cur != NULL) {
			node = cur;
			cur = node->parent;
		}
		return cur;
	}
}
#include "AVL_tree.h"


int main() {
	AVLNode<int>* node = new AVLNode<int>(100);
	node->insert(node, 90);
	node->insert(node, 85);
	node->insert(node, 95);
	node->insert(node, 105);

	node->forward_print(node);
	std::cout << "----------" << std::endl;

	AVLNode<int>* buff = node->left;

	node->right_rotate(node);
	node->forward_print(buff);

	//system("pause");
	return 0;
}
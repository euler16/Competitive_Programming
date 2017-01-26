# include "BST.h"
# include <iostream>

using namespace std;

int main() {

		BST tree = BST(3);
		tree.insert(4);
		tree.insert(2);

		tree.insert(5);

		tree.inorder_traversal();

		return 0;
}
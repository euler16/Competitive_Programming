# ifndef __BST__
# define __BST__

#include <iostream>

template<typename T>
class Node {

public:
		T data;
		Node<T> *left;
		Node<T> *right;

		Node()
		{
				left = nullptr;
				right = nullptr;
		}
		void modify(T data)
		{
				this.data = data;
				return;
		}
};

template <typename T>
class BST {

private:
		static int num_nodes;

public:
		Node<T> *ROOT;
		BST(void)
		{
				ROOT = NULL;
		}
		BST(T data)
		{
				ROOT = new Node<T>;
				ROOT->data = data;
				ROOT->left = nullptr;
				ROOT->right = nullptr;

				num_nodes ++;
		}
		Node<T>* insert(T);
		void inorder_traversal(Node<T> *);
};

template <typename T>
Node<T>* BST<T>::insert(T data,Node<T> node = BST<T>::ROOT)
{

		if(!node) {
				Node<T> *node = new Node<T>;
				node->data = data;
				node->left = nullptr;
				node->right = nullptr;

				return node;	
		}
		
		curr_node = this.ROOT;
		if(data<curr_node->data)
				insert(data,node->right);
		else if(data>node->data)
				insert(data,node->left);

		return curr_node;
}
template<typename T>
void BST<T>::inorder_traversal(Node<T> *node = ROOT)
{
		if (node == nullptr)
				return;

		Node<T> *curr = node;
		while(curr) {
				inorder_traversal(curr->left);
				std::cout<<curr->data;
				inorder_traversal(curr->right);
		}
}
template<typename T>
int BST<T>::num_nodes = 0;

# endif
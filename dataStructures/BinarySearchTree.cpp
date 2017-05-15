#include <iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(): left(NULL), right(NULL){}
};

class BinarySearchTree
{
	Node* root;
public:
	BinarySearchTree(): root(NULL){}
	Node* getRoot();			// Return the root of the Binary Search Tree
	void insert(int x);			// Insert integer in the appropriate location in the tree
	void preorder(Node* node);		// Traverse the tree PreOrder,  root->left->right
	void inorder(Node* node);		// Traverse the tree InOrder,   left->root->right
	void postorder(Node* node);		// Traverse the tree PostOrder, left->right->root
	bool search(int key,Node* node);	// Return true if key exists in the tree, false otherwise
	Node* copy(Node* node);			// Deep copy the tree and return the root of the new one
};

Node* BinarySearchTree::getRoot()
{
	return root;
}
void BinarySearchTree::insert(int x)
{
	Node* newNode = new Node;
	newNode->data = x;

	if(!root)
	{
		root = newNode;
		return;
	}
	
	//Find the right parent for the new node
	Node* prev = NULL;
	Node* curr = root;
	while(curr)
	{
		prev = curr;
		
		if(x < curr->data)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}	
	}
	
	// Insert to the left or right of the parent
	if(x < prev->data)
	{
		prev->left = newNode;
	}
	else
	{
		prev->right = newNode;
	}  
}
void BinarySearchTree::preorder(Node* node)
{
	if(!node)
	{
		return;
	}
	
	std::cout<<"\t"<<node->data;
	preorder(node->left);
	preorder(node->right);	
}
void BinarySearchTree::inorder(Node* node)
{
	if(!node)
        {
	        return;
	}
	
	inorder(node->left);
	std::cout<<"\t"<<node->data;
	inorder(node->right);
}
void BinarySearchTree::postorder(Node* node)
{
	if(!node)
        {
	        return;
	}
	
	postorder(node->left);
	postorder(node->right);
	std::cout<<"\t"<<node->data;
}
bool BinarySearchTree::search(int key,Node* node)
{
	if(!node)
	{
		return false;
	}
	if(key == node->data)
	{
		return true;
	}
	if(key < node->data)
	{
		return search(key,node->left);
	}
	else
	{
		return search(key,node->right);
	} 	
}
Node* BinarySearchTree::copy(Node* node)
{
	if(!node)
	{
		//Tree is empty
		return NULL;
	}

	Node* newRoot = new Node;
	newRoot->data = node->data;
	newRoot->left = copy(node->left);
	newRoot->right= copy(node->right);
	
	return newRoot;
}
int main()
{
	BinarySearchTree bst;
	
	bst.insert(5);
	bst.insert(4);
	bst.insert(6);
	bst.insert(2);
	bst.insert(7);
	bst.insert(3);
	bst.insert(8);

	std::cout<<"Preorder traversal  : ";
	bst.preorder(bst.getRoot());
	std::cout<<std::endl;
	
	std::cout<<"Inorder traversal   : ";
	bst.inorder(bst.getRoot());
	std::cout<<std::endl;
	
	std::cout<<"Postorder traversal : ";
	bst.postorder(bst.getRoot());
	std::cout<<std::endl;

	if(bst.search(5,bst.getRoot()))
	{
		std::cout<<"Search Successful! 5 was found in the tree"<<std::endl;
	}
	else
	{
		std::cout<<"Search Unuccessful! 5 was not found in the tree"<<std::endl;	
	}
	
	if(bst.search(1,bst.getRoot()))
        {       
                std::cout<<"Search Successful! 1 was found in the tree"<<std::endl;
        }
        else
        {
                std::cout<<"Search Unuccessful! 1 was not found in the tree"<<std::endl;
        }

	Node* copiedTree = bst.copy(bst.getRoot());
	std::cout<<"Inorder copied tree : ";
	bst.inorder(copiedTree);
	std::cout<<std::endl;

return 0;
}
/*
Expected Output-
----------------
Preorder traversal  : 	5	4	2	3	6	7	8
Inorder traversal   : 	2	3	4	5	6	7	8
Postorder traversal : 	3	2	4	8	7	6	5
Search Successful! 5 was found in the tree
Search Unuccessful! 1 was not found in the tree
Inorder copied tree : 	2	3	4	5	6	7	8
*/

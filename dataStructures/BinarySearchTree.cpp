#include <iostream>

class Node
{
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node(): parent(NULL), left(NULL), right(NULL){}
};

class BinarySearchTree
{
	Node* root;
public:
	BinarySearchTree(): root(NULL){}
	Node* getRoot();				// Return the root of the Binary Search Tree
	void insert(int x);				// Insert integer in the appropriate location in the tree
	void preorder(Node* root);			// Traverse the tree PreOrder,  root->left->right
	void inorder(Node* root);			// Traverse the tree InOrder,   left->root->right
	void postorder(Node* root);			// Traverse the tree PostOrder, left->right->root
	Node* search(int key,Node* root);		// Return root of the key if it exists in the tree, NULL otherwise
	Node* copy(Node* root);				// Deep copy the tree and return the root of the new one
	Node* getMin(Node* root);			// Get the node with the minimum value with respect to the given root
	Node* deleteItem(int key, Node* root);		// Delete an item from the tree if it is found by search()
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
	
	//Find the right parent for the new root
	Node* curr = root;
	while(curr)
	{
		newNode->parent = curr;
		
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
	if(x < newNode->parent->data)
	{
		newNode->parent->left = newNode;
	}
	else
	{
		newNode->parent->right = newNode;
	}  
}
void BinarySearchTree::preorder(Node* root)
{
	if(!root)
	{
		return;
	}
	
	std::cout<<"\t"<<root->data;
	preorder(root->left);
	preorder(root->right);	
}
void BinarySearchTree::inorder(Node* root)
{
	if(!root)
        {
	        return;
	}
	
	inorder(root->left);
	std::cout<<"\t"<<root->data;
	inorder(root->right);
}
void BinarySearchTree::postorder(Node* root)
{
	if(!root)
        {
	        return;
	}
	
	postorder(root->left);
	postorder(root->right);
	std::cout<<"\t"<<root->data;
}
Node* BinarySearchTree::search(int key,Node* root)
{
	if(!root)
	{
		return NULL;
	}
	if(key == root->data)
	{
		return root;
	}
	if(key < root->data)
	{
		return search(key,root->left);
	}
	else
	{
		return search(key,root->right);
	} 	
}
Node* BinarySearchTree::copy(Node* root)
{
	if(!root)
	{
		//Tree is empty
		return NULL;
	}

	Node* newRoot = new Node;
	newRoot->data = root->data;
	newRoot->parent = root->parent;
	newRoot->left = copy(root->left);
	newRoot->right= copy(root->right);
	
	return newRoot;
}
Node* BinarySearchTree::getMin(Node* root)
{
	if(!root)
	{
		return NULL;
	}
	if(root->left != NULL)
	{
		return getMin(root->left);
	}
	return root;
}
Node* BinarySearchTree::deleteItem(int key, Node* root)
{
	if(!root)
	{
		return NULL;
	}
	if(key < root->data)
	{
		//Look for the key in the left sub-tree
		root->left = deleteItem(key, root->left);
	}
	else if(key > root->data)
	{
		//Look for the key in the right sub-tree
		root->right = deleteItem(key, root->right);
	}
	else
	{
		if((root->left == NULL) && (root->right == NULL))
		{
			//No children
			delete root;
			root = NULL;
		}
		else if(root->left == NULL)
		{
			//1 child to the right
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
                {
			//1 child to the left
                        Node* temp = root;
                        root = root->left;
                        delete temp;
                }
		else
		{
			//Two children
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right= deleteItem(temp->data, root->right);
		}
	 }
	return root;
	
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

	Node* copiedTree = bst.copy(bst.getRoot());
        std::cout<<"Inorder copied tree : ";
        bst.inorder(copiedTree);
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

	bst.deleteItem(3,bst.getRoot());
	std::cout<<"Deleted 3"<<std::endl;
	std::cout<<"Inorder traversal    : ";
        bst.inorder(bst.getRoot());
        std::cout<<std::endl;

	bst.deleteItem(5,bst.getRoot());
	std::cout<<"Deleted 5"<<std::endl;
        std::cout<<"Inorder traversal    : ";
	bst.inorder(bst.getRoot());
        std::cout<<std::endl;

return 0;
}
/*
Expected Output-
----------------
Preorder traversal  : 	5	4	2	3	6	7	8
Inorder traversal   : 	2	3	4	5	6	7	8
Postorder traversal : 	3	2	4	8	7	6	5
Inorder copied tree : 	2	3	4	5	6	7	8
Search Successful! 5 was found in the tree
Search Unuccessful! 1 was not found in the tree
Deleted 3
Inorder traversal    : 	2	4	5	6	7	8
Deleted 5
Inorder traversal    : 	2	4	6	7	8
*/

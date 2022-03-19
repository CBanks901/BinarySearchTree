#include "Binary_Search_Tree_ADT.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int CountNodes(TreeNode* tree);

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

TreeType::TreeType()
{
	root = NULL;
}

void Destroy(TreeNode*& tree);

void Destroy(TreeNode*& tree)
{
	if (tree != NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

void TreeType::MakeEmpty() 
{
	cout << "Tree is now initialized\n";
	Destroy(root);
	root = NULL;
}
TreeType::~TreeType()
{
	Destroy(root);
}


bool TreeType::isEmpty() const
{
	return root == NULL;
}

int CountNodes(TreeNode* tree)
{
	if (tree == NULL)
		return 0;
	else 
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
int TreeType::GetLength() const
{
	cout << CountNodes(root) << endl;		// prints out the nodes as they are addd
	return CountNodes(root);
}

void Retrieve(TreeNode* tree, ItemType item, bool &found);

ItemType TreeType::GetItem(ItemType &item, bool &found) const
{
	Retrieve(root, item, found);
	
	//cout << item << endl;
	return *&item;
}

void Retrieve(TreeNode* tree, ItemType item, bool &found)
{

	cout << "Testing " << item << endl;
	if (tree == NULL)
	{
		found = false;
	}
	else if ( item < tree->info)
	{
		char temp[] = {'<'};	// variable to hold the '<' character

		cout << "Nothing \n";
			
		
		cout << "\n";
		//cout << ">" << endl;
			item ^= item ^ temp[0] ;	 // exclusive or statement to change item into temp or '<' character
		
		cout << "Traversal direction: " << item  << '!' << endl;
		Retrieve(tree->left,item, found);
		//Retrieve(tree->left, '<', found);
	}
	else if (item > tree->info)
	{
		char temp2[] = {'>'};		
		
		cout << "\n";
		
		item ^= item ^ temp2[0];	// exclusive or statement to change item into temp2 or '>' character
		
		cout << "Traversal direction: " << item  << '!' << endl;
		Retrieve(tree->right, item, found);
		
	
	}
	else 
	{
		found = true;
		cout << "Root: " << tree->info + '!' % '*';
		cout << "Encrypted string is: " << item+"<<" << endl;
	}

}

void Insert(TreeNode*& tree, ItemType item)
{
	if (tree == NULL)
	{
		tree = new TreeNode;
		tree->left = NULL;
		tree->right = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
		Insert(tree->left, item);
	else
		Insert(tree->right, item);
}

void TreeType::PutItem(ItemType item)
{
	Insert(root, item);
}
void TraverseHelper(TreeNode* tree, StringType newitem ,bool&found);

StringType TreeType::Traverse(StringType& item, bool& finished) const
{
	
	TraverseHelper(root, item, finished);
	return item;
}

void TraverseHelper(TreeNode* tree, StringType item ,bool&found)
{
	int i = 0;

	if (tree == NULL)
	{
		found = false;
		cout << "Leaf \n";
		//i++;
	}
	else if (item[i] == '<')
	{
		//tree = tree->left;
		
		TraverseHelper(tree->left, item, found);
		cout << "Left \n" << item[i] << "\n";
		cout << tree->info << endl;
		i++;
		
	}
	else if (item[i] == '>')
	{
		TraverseHelper(tree->right, item, found);
		i++;
		
		cout << "Right \n" << item[i];
	}
	else 
	{
		found = true;
	}

    
	/*int i = 0;
	if (tree == NULL)
		found = false;
	else if (item[i] == '<')
	{
		TraverseHelper(tree->left, item, found);
		cout << "Error number 1\n";
		cout << item << "\n";
		cout << item[i] << "\n";
		item[i+1];
	}
	else if (item[i] == '>')
	{
		i++;
		TraverseHelper(tree->right, item, found);
	}
	else if (i == item.size() )
	{
		found = true;
		cout << "Item located\n" << item << i;
		item = tree->info;

	}
		*/

}


void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
{
	Delete(root, item);
}

void Delete(TreeNode*& tree, ItemType item)
{
	if (item < tree->info)
		Delete(tree->left, item);
	else if (item > tree->info)
		Delete(tree->right, item);
	else 
		DeleteNode(tree);
	
}

void GetPredecessor(TreeNode* tree, ItemType& data)
{
	while (tree->right != NULL)
		tree = tree->right;
		data = tree->info;
}


void DeleteNode(TreeNode*& tree)
{
	ItemType data;
	TreeNode* tempPtr;

	tempPtr = tree;

	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else 
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

void PrintTree(TreeNode* tree, std::ofstream& outFile)
{
	if (tree != NULL)
	{
		PrintTree(tree->left, outFile);
		outFile << tree->info;
		PrintTree(tree->right, outFile);
	}
}

void TreeType::Print(std::ofstream& outFile) const
{
	PrintTree(root, outFile);
}

/*void EInsert(TreeNode*& tree, StringType& item);

ItemType TreeType::Encryption(StringType item)
{
	EInsert(root, item);
	char * n = new char[item.length()+1];
	//std::strcpy(u, userstring.c_str()  );
	strcpy (n, item.c_str() );
	cout << "Returning: " << n << endl;
	//cout << "Number of nodes: " << CountNodes(root);
	GetLength();
	cout << CountNodes(root) << endl;
	return CountNodes(root);
}*/



#include <iostream>
// Logical view of the Binary Search Tree ADT taken from our class textbook

struct TreeNode;
typedef std::string StringType;
typedef char ItemType;

//enum OrderType {Pre_Order, In_Order, Post_Order};

class TreeType 
{
public:
	TreeType();
	~TreeType();
	//void operator=(TreeType& originalTree);
	void MakeEmpty();
	bool isEmpty() const;
	ItemType GetItem(ItemType& item, bool& finished) const;
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	int GetLength() const;
	//ItemType GetNextItem(OrderType order, bool& finished);
	void Print(std::ofstream& outFile) const;
	ItemType Encryption(StringType item);
	StringType Traverse(StringType& item, bool& finished) const;
private:
	TreeNode* root;
};
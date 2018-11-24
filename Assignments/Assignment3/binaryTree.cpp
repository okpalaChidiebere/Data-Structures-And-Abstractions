/**********************************************************
student name: okpala chidiebere collins
student number:200356606
main algorithm:
    
************************************************************/
//including all the files needed to run the program
#include<iostream>
#include<fstream>
#include<cstddeF>
#include<new>
using namespace std;

class TreeType;


struct TreeNode
{

	int info;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(int,TreeNode*,TreeNode*);
	friend class TreeType;
};

enum OrderType{PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
private:
	TreeNode* root;
	QueType preQue;
	QueType inQue;
	QueType postQue;

public:
	TreeType();
	~TreeType();
	TreeType(const TreeType& originalTree);
	void Destroy(TreeNode* &tree);
	int LeafCount(TreeNode* tree);
	void Insert(TreeNode* & tree, int item);
	void Print(TreeNode* tree, std::ofstream& outFile);
	void PrintTree(std::ofstream& outFile) const;
	void MakeTree(int item);
	void Ancestors(TreeNode* tree, int item, TreeNode* &nodePtr, TreeNode* & parentPtr,std::ofstream& outFile);
	int SingleParentCount(TreeNode* tree);
	void ResetTree(OrderType order);
	void findNode(TreeNode* tree, int item, TreeNode* &nodePtr, TreeNode* & parentPtr);
	void inOrder(TreeNode* tree, QueType& inque);
	void preOrder(TreeNode* tree, QueType& inque);
	void postOrder(TreeNode* tree, QueType& inque);
	int getNextItem(OrderType order, bool& finished); //getsb the order of tree to be printed
	void putItem(int item);
};


//------------------------information about queue fpr printing in desired order------------------------//
class QueType;

struct queueNode
{
	int info;
	queueNode* next;
	friend class QueType;
};
class EmptyQueue
{};

class FullQueue
{};

class QueType
{
private:
	queueNode* front;
	queueNode* rear;
public:
	QueType();
	~QueType();
	void makeEmpty();
	void Enqueue(int);
	void Dequeue(int&);
	bool IsEmpty()const;
	bool IsFull()const;

};

//----------- Queue function definition -------------------------//
QueType::QueType()
{
front=NULL;
rear=NULL;
}

void QueType::makeEmpty()
{//post: queue is empty: all elements has been disalocated
	queueNode* tempPtr;
	while(front!=NULL)
	{
		tempPtr=front;
		front=front->next;
		delete tempPtr;
	}
	rear=NULL;
}

QueType::QueType()
{
	makeEmpty();
}

void QueType::Enqueue(int newItem)
{
if(IsFull())
	throw FullQueue();
else
{
	queueNode* newNode;
	newNode=new queueNode;
	newNode->info=newItem;
	newNode->next=NULL;
	if(rear==NULL)
		front=newNode;
	else
		rear->next=newNode;
	rear=newNode;
}
}

void QueType::Dequeue(int& item)
{
	if(IsEmpty())
		throw EmptyQueue();
	else
	{
		queueNode* tempPtr;
		tempPtr=front;
		item=front->info;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		delete tempPtr;
	}
}

bool QueType::IsFull()const
{
	queueNode* location;
	try{
		location=new queueNode;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception)
	{
		return true;
	}
}

bool QueType::IsEmpty()const
{
	return(front==NULL);
}
//--------------------infornation about Queue ends------------------------------------------//
//----------- TreeNode function definition -------------------------//
TreeNode::TreeNode(int _number,TreeNode* _left,TreeNode* _right):info(_number),left(_left),right(_right)
{}  //initializer

//-------------------------------------------------
//                TreeType definition
//---------------------------------------------------

//function definition
void Destroy(TreeNode* &tree)
{//post: tree is empty: nodes have been deallocated
	if(tree!=NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

TreeType::~TreeType()
{//calls recursive function destroy to destroy the tree
Destroy(root);
}

TreeType::TreeType()
{
	root=NULL;
}

int LeafCount(TreeNode* tree)
{
	if(tree==NULL)
	return 0;
	else
		return LeafCount(tree->left)+LeafCount(tree->right)+1;
}

void TreeType:: Print(TreeNode* tree, std::ofstream& outFile)
{
	if(tree!=NULL)
	{
		Print(tree->left,outFile); //prints the left subtree
		outFile<<tree->info;
		Print(tree->right,outFile);  //prints the right subtree
	}
}

void TreeType::PrintTree(std::ofstream& outFile) const
{
   Print(root,outFile);
}

void TreeType::ResetTree(OrderType order)
{
	switch(order)
	{
	case PRE_ORDER:preOrder(root, preQue);
                     break;
	case IN_ORDER:inOrder(root, inQue);
		break;
	case POST_ORDER:postOrder(root,postQue);
		break;
	}
}

void preOrder(TreeNode* tree, QueType& preQue)
{
	if(tree!=NULL)
	{
		preQue.Enqueue(tree->info);
		preOrder(tree->left, preQue);
		preOrder(tree->right,preQue);
	}
}

void inOrder(TreeNode* tree, QueType& inQue)
{
	if(tree!=NULL)
	{
		inOrder(tree->left,inQue);
		inQue.Enqueue(tree->info);
		inOrder(tree->right,inQue);
	}
}

void postOrder(TreeNode* tree, QueType& postQue)
{
	if(tree!=NULL)
	{
		postOrder(tree->left,postQue);
		postOrder(tree->right,postQue);
		postQue.Enqueue(tree->info);
	}
}
	
int TreeType::getNextItem(OrderType order, bool& finished)
{
	int item;
	finished=false;
	switch(order)
	{
	case PRE_ORDER:preQue.Dequeue(item);
		if(preQue.IsEmpty())
			finished=true;
                     break;
	case IN_ORDER:inQue.Dequeue(item);
		if(inQue.IsEmpty())
			finished=true;
		break;
	case POST_ORDER:postQue.Dequeue(item);
		if(postQue.IsEmpty())
			finished=true;
		break;
	}
}

void TreeType::Ancestors(TreeNode* tree, int item, TreeNode* &nodePtr, TreeNode* & parentPtr,std::ofstream& outFile)
{
	nodePtr=tree;
	parentPtr=NULL;
	bool found=false;
	while(nodePtr!=NULL&& !found)
	{
		if(item<nodePtr->info)
		{
			parentPtr=nodePtr;
			nodePtr=nodePtr->left;
		}
		else if(item>nodePtr->info)
		{
			parentPtr=nodePtr;
			nodePtr=nodePtr->right;
		}
		else
			found=true;	
	}
	if(found==true)
	{
		Print(parentPtr,outFile);
	}
}

void TreeType::findNode(TreeNode* tree, int item, TreeNode* &nodePtr, TreeNode* & parentPtr)
{
	nodePtr=tree;
	parentPtr=NULL;
	bool found=false;
	while(nodePtr!=NULL&& !found)
	{
		if(item<nodePtr->info)
		{
			parentPtr=nodePtr;
			nodePtr=nodePtr->left;
		}
		else if(item>nodePtr->info)
		{
			parentPtr=nodePtr;
			nodePtr=nodePtr->right;
		}
		else
			found=true;	
	}
}

void TreeType::putItem(int item)
{
	TreeNode* newNode;
	TreeNode* nodePtr;
	TreeNode* parentPtr;

	newNode=new TreeNode(item,NULL,NULL);
	findNode(root,item,nodePtr,parentPtr);

	if(parentPtr==NULL)
		root=newNode;
	else if(item<parentPtr->info)
		parentPtr->left=newNode;
	else
		parentPtr->right=newNode;
}

int sort();
int main()
{

	char cmd;

	return 0;
}

int sort()
{

}

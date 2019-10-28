#include "binary_tree.h"
#include "queue_list.h"
#include <queue>

BinaryTree::BinaryTree()
:m_root(NULL)
{

}

BinaryTree::~BinaryTree()
{
	deleteTree(m_root);
}

BinaryTreeNode* BinaryTree::insertRootNode(Data& data)
{
	if (m_root)
		return NULL;

	m_root = new BinaryTreeNode;
	m_root->nodeData = data;
	//leftSubNode and rightSubNode are initialed as NULL in constructor of BinaryTreeNode 
	/*m_root->leftSubNode = NULL;
	m_root->rightSubNode = NULL;*/
	return m_root;
}

BinaryTreeNode* BinaryTree::insertLeftNode(BinaryTreeNode* parent, Data& data)
{
	if (!parent || parent->leftSubNode)
		return NULL;

	BinaryTreeNode* newNode = new BinaryTreeNode;
	newNode->nodeData = data;//leftSubNode and rightSubNode are initialed as NULL in constructor of BinaryTreeNode 
	parent->leftSubNode = newNode;
	return newNode;
}

BinaryTreeNode* BinaryTree::insertRightNode(BinaryTreeNode* parent, Data& data)
{
	if (!parent || parent->rightSubNode)
		return NULL;

	BinaryTreeNode* newNode = new BinaryTreeNode;
	newNode->nodeData = data;//leftSubNode and rightSubNode are initialed as NULL in constructor of BinaryTreeNode 
	parent->rightSubNode = newNode;
	return newNode;
}

BinaryTreeNode* BinaryTree::findNode(const Data& data, BinaryTreeNode* tree)
{
	if (!tree)
		return NULL;
	
	if (tree->nodeData == data)
		return tree;
	
	BinaryTreeNode* retNode = NULL;
	retNode = findNode(data, getLeftNode(tree));
	if (retNode)
		return retNode;
	retNode = findNode(data, getRightNode(tree));
	if (retNode)
		return retNode;

	return NULL;
}

bool BinaryTree::deleteTree(BinaryTreeNode* tree)
{
	if (!tree)
		return false;

	deleteTree(tree->leftSubNode);
	deleteTree(tree->rightSubNode);
	delete tree;
	tree = NULL;

	return true;
}

void BinaryTree::LDRPrint(BinaryTreeNode* tree) const
{
	if (!tree)
		return;

	LDRPrint(tree->leftSubNode);
	printNodeData(tree);
	LDRPrint(tree->rightSubNode);
}

void BinaryTree::DLRPrint(BinaryTreeNode* tree) const
{
	if (!tree)
		return;

	printNodeData(tree);
	DLRPrint(tree->leftSubNode);
	DLRPrint(tree->rightSubNode);
}

void BinaryTree::LRDPrint(BinaryTreeNode* tree) const
{
	if (!tree)
		return;

	LRDPrint(tree->leftSubNode);
	LRDPrint(tree->rightSubNode);
	printNodeData(tree);
}

void BinaryTree::LevelPrint(BinaryTreeNode* tree) const
{
	if (!tree)
		return;
	//super smart, using queue to store data
	//if you can't understand again, draw a picture to show
	std::queue<BinaryTreeNode*>	queueList;
	queueList.push(tree);
	BinaryTreeNode* curNode = NULL;
	while (!queueList.empty())
	{
		curNode = queueList.front();
		queueList.pop();
		if (!curNode)
			continue;

		cout << curNode->nodeData;

		if (curNode->leftSubNode)
			queueList.push(curNode->leftSubNode);
		if (curNode->rightSubNode)
			queueList.push(curNode->rightSubNode);
	}
}

void BinaryTree::printNodeData(BinaryTreeNode* tree) const
{
	cout << tree->nodeData;
}

int BinaryTree::deepth(BinaryTreeNode* tree) const
{
	if (!tree)
		return 0;

	int lRet = deepth(tree->leftSubNode);
	int rRet = deepth(tree->rightSubNode);

	int ret = lRet > rRet ? lRet : rRet;
	return ret + 1;
}

//////////////////////////////////////////////////////////////////////////
void testBinaryTree()
{
	BinaryTree tree;
	BinaryTreeNode* root = tree.insertRootNode(Data("1001", "zhangsan", 80));
	BinaryTreeNode* left = tree.insertLeftNode(root, Data("1002", "lisi", 30));
	BinaryTreeNode* right = tree.insertRightNode(root, Data("1003", "wangwu", 20));
	tree.insertLeftNode(left, Data("1004", "zhaoliu", 30));
	tree.insertRightNode(left, Data("1005", "wangwu", 20));
	BinaryTreeNode* rr = tree.insertLeftNode(right, Data("1006", "zhaoliu", 30));
	tree.insertRightNode(rr, Data("1007", "zhongqi", 30));

	cout << "tree deepth= " << tree.deepth(root) << endl;
	BinaryTreeNode* node = tree.findNode(Data("1007", "zhongqi", 30), root);
	if (node)
		cout << "find Data('1007', 'zhongqi', 30)" << endl;
	node = tree.findNode(Data("1006", "zhongqi", 30), root);
	if (!node)
		cout << "can not find Data('1006', 'zhongqi', 30)" << endl;
	cout << "LDRPrint:" << endl;
	tree.LDRPrint(root);
	cout << "DLRPrint:" << endl;
	tree.DLRPrint(root);
	cout << "LRDPrint:" << endl;
	tree.LRDPrint(root);
	cout << "LevelPrint:" << endl;
	tree.LevelPrint(root);
}

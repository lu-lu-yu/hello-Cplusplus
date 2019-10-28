#ifndef _H_BINARY_TREE_H_
#define _H_BINARY_TREE_H_

#include "data.h"
#include <iostream>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	BinaryTreeNode*	insertRootNode(Data& data);
	BinaryTreeNode*	insertLeftNode(BinaryTreeNode* parent, Data& data);
	BinaryTreeNode*	insertRightNode(BinaryTreeNode* parent, Data& data);
	BinaryTreeNode*	findNode(const Data& data, BinaryTreeNode* tree);
	BinaryTreeNode*	getLeftNode(BinaryTreeNode* tree)const { return tree ? tree->leftSubNode : NULL; }
	BinaryTreeNode*	getRightNode(BinaryTreeNode* tree)const { return tree ? tree->rightSubNode : NULL; }
	bool			isEmpty()const { return !m_root; }
	bool			deleteTree(BinaryTreeNode* tree);
	void			LDRPrint(BinaryTreeNode* tree)const;//«∞–Ú
	void			DLRPrint(BinaryTreeNode* tree)const;//÷––Ú
	void			LRDPrint(BinaryTreeNode* tree)const;//∫Û–Ú
	void			LevelPrint(BinaryTreeNode* tree)const;//≤„–Ú
	void			printNodeData(BinaryTreeNode* tree) const;
	int				deepth(BinaryTreeNode* tree)const;

private:
	BinaryTreeNode*		m_root;
};

void	testBinaryTree();

#endif
#pragma once
#include "stdafx.h"

class Tree
{
private:
	Data m_treedata;
	Tree *m_leftTree;
	Tree *m_rightTree;

public:
	Tree(Data data);
	~Tree();

	void InsertLeftTree(Tree* head, Tree* newTree);
	void InsertRightTree(Tree* head, Tree* newTree);
	Data GetTreeData(Tree* find);
	void SetTreeData(Tree* find, Data data);
	Tree* GetLeftSubTree(Tree* head);
	Tree* GetRightSubTree(Tree* head);
};
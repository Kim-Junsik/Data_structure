#include "stdafx.h"
#include "Tree.h"

Tree::Tree(Data data = 0)
	:m_leftTree(NULL), m_rightTree(NULL)
{
	m_treedata = data;
}

Tree::~Tree()
{
	
}

void Tree::InsertLeftTree(Tree * head, Tree* newTree)
{
	if (head->m_leftTree != NULL)
	{
		delete head->m_leftTree;
	}
	head->m_leftTree = newTree;
}

void Tree::InsertRightTree(Tree * head, Tree * newTree)
{
	if (head->m_rightTree != NULL)
	{
		delete head->m_rightTree;
	}
	head->m_rightTree = newTree;
}

Data Tree::GetTreeData(Tree * find)
{
	return find->m_treedata;
}

void Tree::SetTreeData(Tree * find, Data data)
{
	find->m_treedata = data;
}

Tree * Tree::GetLeftSubTree(Tree * head)
{
	return head->m_leftTree;
}

Tree * Tree::GetRightSubTree(Tree * head)
{
	return head->m_rightTree;
}

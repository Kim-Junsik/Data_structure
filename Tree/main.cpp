#include "stdafx.h"
#include "Tree.h"

void InorderTraverse(Tree* head)
{
	if (head == NULL)
	{
		return;
	}

	InorderTraverse(head->GetLeftSubTree(head));
	cout << head->GetTreeData(head);
	InorderTraverse(head->GetRightSubTree(head));
}

void PreorderTraverse(Tree* head)
{
	if (head == NULL)
	{
		return;
	}

	cout << head->GetTreeData(head);
	PreorderTraverse(head->GetLeftSubTree(head));
	PreorderTraverse(head->GetRightSubTree(head));
}

void PostorderTraverse(Tree* head)
{
	if (head == NULL)
	{
		return;
	}

	PostorderTraverse(head->GetLeftSubTree(head));
	PostorderTraverse(head->GetRightSubTree(head));
	cout << head->GetTreeData(head);
}


Tree * CreateTree(Data data)
{
	Tree *newtree = new Tree(data);

	return newtree;
}


int main()
{
	Tree *head = CreateTree(1);

	Tree *mk2 = CreateTree(2);
	Tree *mk3 = CreateTree(3);
	Tree *mk4 = CreateTree(4);
	Tree *mk5 = CreateTree(5);
	Tree *mk6 = CreateTree(6);

	head->InsertLeftTree(head, mk2);
	head->InsertRightTree(head, mk3);
	mk2->InsertLeftTree(mk2, mk4);
	mk2->InsertRightTree(mk2, mk5);
	mk3->InsertLeftTree(mk3, mk6);

	cout << "--------중위순회--------" << endl;
	InorderTraverse(head);
	cout << endl;
	cout << "--------전위순회--------" << endl;
	PreorderTraverse(head);
	cout << endl;
	cout << "--------후위순회--------" << endl;
	PostorderTraverse(head);
	cout << endl;
	return 0;
}
/*���� ���� ����Ʈ*/
#include <iostream>
#include "DoublyLinked_List.h"

using namespace std;

void main()
{
	Node* node = new Node();

	node->Linked(node, 45);
	node->Linked(node, 19);
	node->Linked(node, 20);
	node->Linked(node, 69);

	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);

	node->Insert(node, 100, 1);
	cout << "���θ��� ��� : 1�����" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);
	node->Print(node, 5);

	node->Detele(node, 2);
	cout << "���� ��� : 2�� ���" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);


	node->Sort(node);
	cout << "��� �������� ����" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);

	delete node;
}
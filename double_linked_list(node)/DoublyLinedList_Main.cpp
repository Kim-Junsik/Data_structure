/*더블 연결 리스트*/
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
	cout << "새로만든 노드 : 1번노드" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);
	node->Print(node, 5);

	node->Detele(node, 2);
	cout << "삭제 노드 : 2번 노드" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);


	node->Sort(node);
	cout << "노드 오름차순 정렬" << endl;
	node->Print(node, 1);
	node->Print(node, 2);
	node->Print(node, 3);
	node->Print(node, 4);

	delete node;
}
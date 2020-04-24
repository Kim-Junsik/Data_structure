#include "DoublyLinked_List.h"

using namespace std;

Node::Node()
	:Data(NULL), Next(NULL), Count(NULL), Pre(NULL)
{
}

void Node::Linked(Node* node, int Data)		//���ο��� �߰� �Լ�(����)
{
	Node* NewNode = CreateNode(Data);
	Node* Cur = node;
	
	if (node->Next == NULL)
	{
		node->Next = NewNode;
		NewNode->Pre = node;
		Count++;
	}
	else
	{
		while (Cur->Next != NULL)
		{
			Cur = Cur->Next;
		}
		Cur->Next = NewNode;
		NewNode->Pre = Cur;
		Count++;
	}

}

Node* Node::CreateNode(int Data)		//���ο� ��� ����
{
	Node* NewNode = new Node();
	NewNode->Data = Data;

	return NewNode;
}

void Node::Detele(Node* node, int DeleteNum)			//��� ���� �Լ�
{
	Node* Front = node->Next->Next;
	Node* Cur = node->Next;
	Node* Back = node;
	
	if (DeleteNum > Count)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		return;
	}
	else
	{
		for (size_t i = 1; i < DeleteNum; i++)
		{
			Back = Cur;
			Cur = Cur->Next;
			Front = Front->Next;
		}
		Back->Next = Cur->Next;
		Front->Pre = Cur->Pre;
		delete Cur;
		Count--;
	}
}

void Node::Sort(Node* node)		//��� ���� �Լ�(�����Ʈ)
{
	Node* Cur = node->Next;
	Node* Back = node;
	int temp = 0;
	if ((Back->Data == NULL) | (Cur->Data == NULL))
	{
		if (Cur->Next == NULL)
		{
			cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
			return;
		}
		Back = Back->Next;
		Cur = Cur->Next;
	}

	for (size_t j = 0; j < Count-1; j++)
	{
		for (size_t i = 0; i < Count-1; i++)
		{
			if (Back->Data > Cur->Data)
			{
				temp = Back->Data;
				Back->Data = Cur->Data;
				Cur->Data = temp;

				Back = Back->Next;
				Cur = Cur->Next;
			}
		}
		Back = node;
		Cur = node->Next;
	}
}

void Node::Insert(Node* node,int Data, int Num)		//��� ���� �Լ�
{
	Node* InsertNode = CreateNode(Data);
	Node* Back = node;
	Node* Cur = node->Next;

	if (Num > Count)
	{
		cout << "�߸��� ���� �Է��ϼ̽��ϴ�." << endl;
		return;
	}
	else
	{
		for (size_t i = 1; i < Num; i++)
		{
			Back = Back->Next;
			Cur = Cur->Next;
		}
		InsertNode->Next = Cur;
		Cur->Pre = InsertNode;

		Back->Next = InsertNode;
		InsertNode->Pre = Back;
		Count++;
	}
}

void Node::Print(Node* Head, int i)		//����� ������ ���
{
	Node* Cur = Head;

	if (i > Count)
	{
		cout << "�߸��� ����Դϴ�." << endl;
		return;
	}
	else
	{
		for(size_t j = 0; j<i;j++)
		{
			Cur = Cur->Next;
		}
		cout << i << "��° ��� ��� : " << Cur->Data << endl;
	}
}

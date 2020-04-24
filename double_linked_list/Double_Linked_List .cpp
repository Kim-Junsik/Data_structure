#include <iostream>

using namespace std;



class Node
{
public:
	Node()
		:Data(NULL), Size(NULL), Right(NULL), Left(NULL)
	{

	}

	void LinkList(Node *Head,int Data)
	{
		CreateNode(Head, MakeNode(Data));
	}

	Node *MakeNode(int Data)
	{
		Node *NewNode = new Node();
		NewNode->Data = Data;
		
		Size++;

		return NewNode;
	}

	void CreateNode(Node *Head, Node *Newnode)
	{	
		Node *CheckRight = Head->Right;
		Node *CheckLeft = Head->Left;

		if ((CheckRight == NULL) & (CheckLeft == NULL))
		{
			Head->Right = Newnode;
		}
		else
		{
			while (CheckRight != NULL)
			{
				CheckLeft = CheckRight->Left;
				CheckRight = CheckRight->Right;
				
			}
			
			CheckRight = Newnode;
			Newnode->Left = CheckLeft->Right;
		}
	}
private:
	int Data;
	int Size;
	Node *Right;
	Node *Left;
};


void main()
{
	Node List;
	Node *Head = &List;

	List.LinkList(Head, 10);
	List.LinkList(Head, 20);
	List.LinkList(Head, 30);
	List.LinkList(Head, 40);
	List.LinkList(Head, 50);

	int debug = 0;
}
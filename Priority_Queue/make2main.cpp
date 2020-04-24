#include "Priority_Queue.h"

int main()
{
	Priority priority(4);
	priority.Insert("ABCDEF");
	priority.Insert("ABCD");
	priority.Insert("AB");
	priority.Insert("ABCDEFG");
	cout << priority.Delete() << endl;
	cout << priority.Delete() << endl;
	cout << priority.Delete() << endl;
	cout << priority.Delete() << endl;
	cout << "----------------------------------------" << endl;
	priority.Insert("ABCD");
	priority.Insert("ABCDEFG");
	priority.Insert("ABC");
	priority.Insert("A");
	while (!priority.empty())
	{
		cout << priority.Delete() << endl;
	}
}
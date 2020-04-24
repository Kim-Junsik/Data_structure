#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
	Heap *heap = new Heap;
	heap->Hinit(heap);

	heap->Hinsert(heap, 1);
	heap->Hinsert(heap, 2);
	heap->Hinsert(heap, 3);
	printf("%d \n", heap->Hdelete(heap));

	heap->Hinsert(heap, 1);
	heap->Hinsert(heap, 2);
	heap->Hinsert(heap, 3);
	printf("%d \n", heap->Hdelete(heap));

	while (!(heap->Hempty(heap)))
		printf("%d \n", heap->Hdelete(heap));
	return 0;
}
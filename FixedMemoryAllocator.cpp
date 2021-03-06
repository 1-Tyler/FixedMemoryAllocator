// FixedMemoryAllocator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MemoryManager.h"
#include "MemoryManager.cpp"
#include <assert.h>


int main()
{
	MemoryManager<int> myInts(10);
	
	//Fill up memory
	for (int i = 0; i < 8; i++)
	{
		myInts.addToMemory(i);
	}

	//Try to overflow memory
	myInts.addToMemory(75);
	myInts.addToMemory(32);
	myInts.addToMemory(21);

	//Verify overflow data was not stored
	assert(!myInts.contains(75));
	assert(!myInts.contains(32));
	assert(!myInts.contains(21));

	//Remove data from memory & verify that is it removed
	myInts.removeFromMemory(1);
	assert(!myInts.contains(1));

	//Add new data to memory and verify that it is present
	myInts.addToMemory(75);
	assert(myInts.contains(75));

    return 0;
}


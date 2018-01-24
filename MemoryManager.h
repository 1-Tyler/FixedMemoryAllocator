#pragma once
#include<vector>

/*
*Memory manager which stores data. The warning buffer has a fixed size of 20% of the total memory
*size, which will log an error then return without saving the data if at max capacity.
*/
template<class T>
class MemoryManager
{
private:
	int memorySize;
	int basePointer;
	int warningZoneTotalSize;
	std::vector<T> memoryArray;

	int getNextFreeBlock();
public:
	MemoryManager();
	MemoryManager(int size);
	~MemoryManager();

	void addToMemory(T element);
	void removeFromMemory(T element);
	bool contains(T element);
};


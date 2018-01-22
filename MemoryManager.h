#pragma once
#include<vector>

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
};


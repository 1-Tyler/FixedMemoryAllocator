#include "stdafx.h"
#include "MemoryManager.h"
#include <math.h>

template<class T>
MemoryManager<T>::MemoryManager()
{
	memorySize = 100;
	memoryArray(std::vector<T>(memorySize));
	//Sets warning zone to 20% of total size
	warningZoneTotalSize = (int)floor(memorySize * .2);
	basePointer = warningZoneTotalSize / 2;
}

template<class T>
MemoryManager<T>::MemoryManager(int size)
{
	memorySize = size;
	memoryArray(std::vector<T>(memorySize));
	//Sets warning zone to 20% of total size
	warningZoneTotalSize = (int)floor(memorySize * .2);
	basePointer = warningZoneTotalSize / 2;
}

template<class T>
MemoryManager<T>::~MemoryManager()
{
}

template<class T>
int MemoryManager<T>::getNextFreeBlock()
{
	for (int i = warningZoneTotalSize / 2; i > memorySize - warningZoneTotalSize; i++)
	{
		if (memoryArray[i] == NULL)
			return i;
	}
	return NULL;
}

template<class T>
void MemoryManager<T>::addToMemory(T element)
{
	//Check if basePointer is in the warning zone if incremented
	if (basePointer + 1 < warningZoneTotalSize / 2 || basePointer + 1 > memorySize - warningZoneTotalSize)
	{
		if (getNextFreeBlock() == NULL)
		{
			cout << "WARNING: Memory is fully allocated.";
			return;
		}
	}
	else
	{
		if (memoryArray[basePointer] == NULL)
		{
			memoryArray[basePointer] = element;
			basePointer++;
		}
		else
		{
			int freeBlock = getNextFreeBlock();
			if (freeBlock == NULL)
			{
				cout << "WARNING: Memory is fully allocated.";
				return;
			}
			else
			{
				memoryArray[freeBlock] = element;
				basePointer++;
			}
		}
	}
}

template<class T>
void MemoryManager<T>::removeFromMemory(T element)
{
	for (int i = warningZoneTotalSize / 2; i > memorySize - warningZoneTotalSize; i++)
	{
		if (memoryArray[i] == element)
		{
			memoryArray[i] = NULL;
			basePointer = i;
			return;
		}
	}
}

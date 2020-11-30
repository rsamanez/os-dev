#pragma once
#include "TypeDefs.h"
#include "Memory.h"

struct MemorySegmentHeader{
	uint_64 MemoryLenght;
	MemorySegmentHeader* NextSegment;
	MemorySegmentHeader* PreviousSegment;
	MemorySegmentHeader* NextFreeSegment;
	MemorySegmentHeader* PreviousFreeSegment;
	bool Free;
};

struct AlignedMemorySegmentHeader{
	uint_64 MemorySegmentHeaderAddress: 63;
	bool IsAligned : 1;
};

void InitializeHeap(uint_64 heapAddress, uint_64 heapLength);

void* calloc(uint_64 size);
void* calloc(uint_64 num, uint_64 size);
void* malloc(uint_64 size);
void* realloc(void* address, uint_64 newSize);
void* aligned_alloc(uint_64 aligment, uint_64 size);

void free(void* address);

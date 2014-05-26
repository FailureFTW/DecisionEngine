#include "tt.h"

TranspositionTable TT;

	// Returns a pointer to the first entry in the transposition table.

TTEntry* TranspositionTable::First_Entry() const
{
	return table;
}

	// Searches the transposition table for an entry with the given key ans returns a pointer to that entry.
	// Returns NULL if nothing is found.
//const TTEntry* TranspositionTable::Probe(const KeyType key) const
//{
//	TTEntry* tte = First_Entry();
//
//}

void TranspositionTable::Resize(uint32_t size_MB)
{
	// assert(Log2Fast(size_MB << 20)/sizeof(TTENtry) < 32);

	long size = 1 << (Log2Fast(size_MB << 20) / sizeof(TTEntry));

	mem = calloc(size * sizeof(TTEntry), 1);
	memset(mem, 0, size);
	table = (TTEntry*)(mem);
}

void TranspositionTable::clear()
{
	std::memset(table, 0, sizeof(TTEntry));
}

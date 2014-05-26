#include "tt.h"

	// Returns a pointer to the first entry in the transposition table.

TTEntry* TranspositionTable::First_Entry() const
{
	return table;
}

	// Searches the transposition table for an entry with the given key ans returns a pointer to that entry.
	// Returns NULL if nothing is found.
const TTEntry* TranspositionTable::Probe(const KeyType key) const
{
	return table;
}

void TranspositionTable::Resize(uint32_t size_MB)
{

}

void TranspositionTable::clear()
{
	
}

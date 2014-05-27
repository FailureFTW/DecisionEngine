#include "tt.h"

	// Returns the slot in which an entry would normally go.
	// This will the the first slot to look at when storing
	// entries.

TTEntry* TranspositionTable::First_Entry(const KeyType Key) const
{
	return table;
}

	// Searches the transposition table for an entry with the given key ans returns a pointer to that entry.
	// Returns NULL if nothing is found.
const TTEntry* TranspositionTable::Probe(const KeyType key) const
{
	return table;
}
	// The transposition table is resized to a power of 2 number of TTEntries
	// that is less than or equal to the specified size in Megabytes.
void TranspositionTable::Resize(uint32_t size_MB)
{	
		// Make sure the number of TTEntries does not exceed 2^32 entries
		// which is the limit of the number of entries a 32 bit hash key
		// can have.
	assert(Log2Fast((size_MB << 20) / sizeof(TTEntry)) < 32);

		// Size is number of TTEntries
	uint32_t size = 1 << Log2Fast((size_MB << 20) / sizeof(TTEntry));

		// Size is 2^x, hash mask equals 2^x-1. Size is, for example
		// 2^8 = (00001 0000 0000) entries, which range from 0 = (0000 0000 0000) to 2^8-1 = (0000 1111 1111).
		// The key will be logical AND'ed with the mask to find the ID of the entry.
	hashMask = size-1;

}

void TranspositionTable::clear()
{
	
}

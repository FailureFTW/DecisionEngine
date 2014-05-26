#ifndef TT_H
#define TT_H

#include "Includes.h"
#include "BitFuncs.h"

	/*
	 * Transposition tables store the valuable data about a position.
	 * A unique key is made to match a unique board position.
	 * Before analyzing a position, the engine will search the transposition table
	 *     to see if that same postition was already visited.
	 * This allows the engine to ignore positions that were already evaluated.
	 * There are usually many ways a postition can be reached.
	 * This helps avoid examining a position twice and saves massively on power and space.
	 * Typically not much more data will be needed than what is stored in the table once that
	 *     position was analyzed.
	 *	See http://en.wikipedia.org/wiki/Transposition_table for more information.
	 */

	// TTEntry is the table itself. There will be millions of entries.
struct TTEntry
{
		// This saves the data to the table.
	void Save (KeyType k, ScoreType s, ScoreType e, MoveType m, DepthType d, GenType g)
	{
		key = k; score = s; evalScore = e; move = m; depth = d; gen = g;
	}

		// These functions get the data from the table. This is better than making the data publicly available
	KeyType Key() const		{ return key; }
	ScoreType Score() const { return score; }
	ScoreType EvalScore() const { return evalScore; }
	MoveType Move() const	{ return move; }
	DepthType Depth() const	{ return depth; }
	
private:
		// TranspositionTable class can directly access the data.
	friend class TranspositionTable;

		// The data itself is here.
	KeyType key;	// Key needed to access an entry
	ScoreType score;	// Score of this position. Can be direct or through child nodes
	ScoreType evalScore;	// Evaluated score of this particular position
	MoveType move;	// Move leading up to this position
	DepthType depth;	// Depth of this node
	GenType gen;	// With every new search, the generation increases
};

	// This class is used to manipulate the transposition table.
class TranspositionTable
{

public:
	~TranspositionTable() { free(mem); }	// Resource cleanup
	void New_Search() { ++gen; }	// Updates the current generation when a new search is called

		// These functions do the actual maipulation of the table.

	void init();
	TTEntry* First_Entry() const;
	const TTEntry* Probe(const KeyType key) const;
	void Store(KeyType k, ScoreType s, ScoreType e, MoveType m, DepthType d, GenType g);
	void Resize(uint32_t size_MB);
	void clear();

private:
	uint32_t hashMask;	// Mask for the current table size
	TTEntry* table;	// Pointer to table entry currently in use
	void* mem;	// Pointer to the whole table
	GenType gen;	// Size must be not bigger than TTEntry::gen
};

extern TranspositionTable TT;

#endif

// Remember to use bucket hashing
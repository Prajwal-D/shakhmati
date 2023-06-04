#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "BitBoard.hpp"
#include "Move.hpp"
#include <vector>

namespace MoveGen
{
    static BitBoard WHITE_PIECES;
    static BitBoard BLACK_PIECES;
    static BitBoard EMPTY;
    void init_MoveGen();
    void update_constants(const AllBoards& b);
    std::vector<Move> white_pawn_moves(BitBoard pawns,BitBoard en_passant_target_sq);
    std::vector<Move> black_pawn_moves(BitBoard pawns,BitBoard en_passant_target_sq);
    
}

#endif
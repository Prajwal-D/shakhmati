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
    void InitMoveGen();
    void UpdateConstants(const AllBoards& b);
    std::vector<Move> WhitePawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    std::vector<Move> BlackPawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    
}

#endif
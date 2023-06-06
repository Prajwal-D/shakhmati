#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "../../headers/BitBoard.hpp"
#include "../../headers/Move.hpp"
#include <vector>

namespace MoveGen
{
    extern BitBoard WHITE_PIECES;
    extern BitBoard BLACK_PIECES;
    extern BitBoard EMPTY;
    void InitMoveGen();
    void UpdateConstants(const AllBoards& b);
    std::vector<Move> WhitePawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    std::vector<Move> BlackPawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    
}

#endif
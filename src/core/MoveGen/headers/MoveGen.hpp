#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "../../headers/BitBoard.hpp"
#include "../../headers/Move.hpp"
#include <vector>

namespace MoveGen
{
    extern BitBoard white_pieces_;
    extern BitBoard black_pieces_;
    extern BitBoard empty_squares_;
    void InitMoveGen();
    void UpdateConstants(const AllBoards& b);
    std::vector<Move> WhitePawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    std::vector<Move> BlackPawnMoves(BitBoard pawns,BitBoard en_passant_target_sq);
    
}

#endif
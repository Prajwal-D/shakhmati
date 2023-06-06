#include "headers/MoveGen.hpp"
BitBoard MoveGen::WHITE_PIECES = 0ull;
BitBoard MoveGen::BLACK_PIECES = 0ull;
BitBoard MoveGen::EMPTY = 0ull;

void MoveGen::InitMoveGen()
{
    WHITE_PIECES = 0ull;
    BLACK_PIECES = 0ull;
    EMPTY = ~WHITE_PIECES;
}
void MoveGen::UpdateConstants(const AllBoards& b)
{
    WHITE_PIECES = b.white_kings_ | b.white_queens_ | b.white_bishops_ | b.white_knights_ | b.white_rooks_ | b.white_pawns_;
    BLACK_PIECES = b.black_kings_ | b.black_queens_ | b.black_bishops_ | b.black_knights_ | b.black_rooks_ | b.black_pawns_;
    EMPTY = ~(WHITE_PIECES | BLACK_PIECES);
}

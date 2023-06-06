#include "headers/MoveGen.hpp"
BitBoard MoveGen::white_pieces_ = 0ull;
BitBoard MoveGen::black_pieces_ = 0ull;
BitBoard MoveGen::empty_squares_ = 0ull;

void MoveGen::InitMoveGen()
{
    white_pieces_ = 0ull;
    black_pieces_ = 0ull;
    empty_squares_ = ~white_pieces_;
}
void MoveGen::UpdateConstants(const AllBoards& b)
{
    white_pieces_ = b.white_kings_ | b.white_queens_ | b.white_bishops_ | b.white_knights_ | b.white_rooks_ | b.white_pawns_;
    black_pieces_ = b.black_kings_ | b.black_queens_ | b.black_bishops_ | b.black_knights_ | b.black_rooks_ | b.black_pawns_;
    empty_squares_ = ~(white_pieces_ | black_pieces_);
}

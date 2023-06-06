#ifndef MAGICCONSTANTS_HPP
#define MAGICCONSTANTS_HPP

#include "BitBoard.hpp"
typedef uint32_t PieceType; 
typedef uint64_t BitBoard;
#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

template<typename T>
constexpr BitBoard IndexToBB(T index){return 1ull << static_cast<unsigned>(index);}

namespace Magics
{
    [[nodiscard]] constexpr BitBoard PopLSB(BitBoard board){return board & (board-1);}

    //consts for move gen
    constexpr BitBoard FILE_A = 0x0101010101010101;
    constexpr BitBoard FILE_B = FILE_A << 1;
    constexpr BitBoard FILE_C = FILE_A << 2;
    constexpr BitBoard FILE_D = FILE_A << 3;
    constexpr BitBoard FILE_E = FILE_A << 4;
    constexpr BitBoard FILE_F = FILE_A << 5;
    constexpr BitBoard FILE_G = FILE_A << 6;
    constexpr BitBoard FILE_H = FILE_A << 7;

    constexpr BitBoard RANK_1 = 0x00000000000000FF;
    constexpr BitBoard RANK_2 = RANK_1 << 8;
    constexpr BitBoard RANK_3 = RANK_1 << 16;
    constexpr BitBoard RANK_4 = RANK_1 << 24;
    constexpr BitBoard RANK_5 = RANK_1 << 32;
    constexpr BitBoard RANK_6 = RANK_1 << 40; 
    constexpr BitBoard RANK_7 = RANK_1 << 48;
    constexpr BitBoard RANK_8 = RANK_1 << 56;

    //constants for the move recording system
    constexpr PieceType KING         = 0x01u;
    constexpr PieceType QUEEN        = 0x02u;
    constexpr PieceType BISHOP       = 0x03u;
    constexpr PieceType KNIGHT       = 0x04u;
    constexpr PieceType ROOK         = 0x05u;
    constexpr PieceType PAWN         = 0x06u;
    constexpr uint32_t START_SQ_MASK    = 0x0000003F;
    constexpr uint32_t END_SQ_MASK      = 0x00000FC0;
    constexpr uint32_t PIECE_TYPE_MASK  = 0x00007000;
    constexpr uint32_t COLOUR_MASK     = 0x00008000;
    constexpr uint16_t END_SQ_SHIFT     = 6;
    constexpr uint16_t PIECE_TYPE_SHIFT = 12;
    constexpr uint16_t COLOUR_SHIFT   = 15;
}
#endif 
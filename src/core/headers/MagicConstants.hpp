#ifndef MAGICCONSTANTS_HPP
#define MAGICCONSTANTS_HPP

#include "BitBoard.hpp"
namespace Magics
{
    [[nodiscard]] constexpr BitBoard PopLSB(BitBoard board){return board & (board-1);}

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
}
#endif 
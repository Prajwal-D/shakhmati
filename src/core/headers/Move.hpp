#ifndef MOVE_HPP
#define MOVE_HPP
#include <cstdint>
#include "MagicConstants.hpp"

typedef uint16_t Move;
/*
move storage: 
from right to left:
6 bits - start index
6 bits - end index
3 bits - piece type 
1 bit  - colour (white = 1/black = 0)
*/
namespace Moves
{
    [[nodiscard]] constexpr Move encode_move(const int start_index, const int target_index,const int piece_type,const bool is_white);

    constexpr void decode_move(const Move move,int& start_index, int& target_index,int& piece_type,bool& is_white);
    
    constexpr bool is_white(const Move move)            {return (move >> Magics::COLOUR_SHIFT) == 1;}
    constexpr PieceType get_piece_type(const Move move) {return (move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT;}
    constexpr int get_target_index(const Move move)     {return(move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT;}
    constexpr int get_start_index(const Move move)      {return move & Magics::START_SQ_MASK;}
}
#endif
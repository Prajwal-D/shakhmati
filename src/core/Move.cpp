#include "headers/Move.hpp"

namespace Moves
{
    [[nodiscard]] constexpr Move encode_move(const int start_index, const int target_index,const int piece_type,const bool is_white)
    {
        Move move{0};
        move |= start_index & Magics::START_SQ_MASK;
        move |= (target_index & Magics::START_SQ_MASK) << Magics::END_SQ_SHIFT;
        move |= (piece_type << Magics::PIECE_TYPE_SHIFT) & Magics::PIECE_TYPE_MASK ;
        move |= (is_white ? 1u : 0u) << Magics::COLOUR_SHIFT;
        return move;
    }
    constexpr void decode_move(const Move move,int& start_index, int& target_index,int& piece_type,bool& is_white)
    {
        start_index = move & Magics::START_SQ_MASK;
        target_index =  (move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT;
        piece_type = (move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT;
        is_white = (move >> Magics::COLOUR_SHIFT) == 1;
    }
}
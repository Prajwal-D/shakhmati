#ifndef MOVE_HPP
#define MOVE_HPP
#include <cstdint>
#include "MagicConstants.hpp"
#include <algorithm>
typedef uint16_t Move;
/*
Move storage: 
from right to left:
6 bits - start index
6 bits - end index
3 bits - piece type 
1 bit  - colour (white = 1/black = 0)
E.g. 
 0      | 000        | 000000     | 000000
 colour   piece type   end index    start index
*/
constexpr bool operator==(std::vector<Move> v1, std::vector<Move> v2)
{
    if(v1.size() != v2.size()) return false;
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());
    for(std::size_t i = 0; i < v1.size();++i)
    {
        if(v1.at(i) != v2.at(i)) return false;
    }
    return true;
}
namespace Moves
{
    [[nodiscard]] constexpr Move EncodeMove(const int start_index, const int target_index,const int piece_type,const bool IsWhite)
    {
        Move move{0};
        move |= start_index & Magics::START_SQ_MASK;
        move |= (target_index & Magics::START_SQ_MASK) << Magics::END_SQ_SHIFT;
        move |= (piece_type << Magics::PIECE_TYPE_SHIFT) & Magics::PIECE_TYPE_MASK ;
        move |= (IsWhite ? 1u : 0u) << Magics::COLOUR_SHIFT;
        return move;
    }
    constexpr void DecodeMove(const Move move,int& start_index, int& target_index,int& piece_type,bool& IsWhite)
    {
        start_index = move & Magics::START_SQ_MASK;
        target_index =  (move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT;
        piece_type = (move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT;
        IsWhite = (move >> Magics::COLOUR_SHIFT) == 1;
    }
    constexpr bool IsWhite(const Move move)            {return (move >> Magics::COLOUR_SHIFT) == 1;}
    constexpr PieceType GetPieceType(const Move move) {return (move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT;}
    constexpr int GetTargetIndex(const Move move)     {return(move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT;}
    constexpr int GetStartIndex(const Move move)      {return move & Magics::START_SQ_MASK;}
}
#endif
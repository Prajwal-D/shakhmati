#include <iostream>
#include "core/headers/Debug.hpp"
#include "core/headers/BitBoard.hpp"
#include "core/headers/MoveGen.hpp"
#include "core/headers/MagicConstants.hpp"
int main(void)
{
    /*
    BitBoard state{Magics::FILE_A};
    Debug::print_bb(state,true);
    */
    //Debug::print_encoded_move_str(Moves::encode_move(63,44,Magics::KNIGHT,false));
    /*
    int index = 0;
    if(str == a ) index += 20;
    else index += 40;
    
    bb = 1ull << index;
    static_cast<EP>(bb);
    */
    //Debug::print_bb();
    MoveGen::init_MoveGen();
    std::vector<Move> PossibleMoves = MoveGen::white_pawn_moves(BitBoard(0x0000100),BitBoard(0));
    for (const Move& i : PossibleMoves)
    {
        Debug::print_encoded_move_str(i);
    }
    

    
    return 0;
}
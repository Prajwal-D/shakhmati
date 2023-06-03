#include <iostream>
#include "core/headers/Debug.hpp"
#include "core/headers/BitBoard.hpp"
#include "core/headers/MagicConstants.hpp"
int main(void)
{
    /*
    BitBoard state{Magics::FILE_A};
    Debug::print_bb(state,true);
    */
    Debug::print_encoded_move_str(Moves::encode_move(63,44,Magics::KNIGHT,false));
    return 0;
}
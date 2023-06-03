#include <iostream>
#include "core/headers/Debug.hpp"
#include "core/headers/BitBoard.hpp"
#include "core/headers/MagicConstants.hpp"
int main(void)
{
    BitBoard state{Magics::FILE_A};
    Debug::print_bb(state,true);
    return 0;
}
#include <iostream>
#include "core/headers/Debug.hpp"
#include "core/headers/BitBoard.hpp"
#include "core/headers/MoveGen.hpp"
#include "core/headers/MagicConstants.hpp"
#include "core/headers/Testing.hpp"
int main(void)
{
    /*
    BitBoard state{Magics::FILE_A};
    Debug::print_bb(state,true);
    */
    //Debug::print_encoded_move_str(Moves::encode_move(63,44,Magics::KNIGHT,false));
    //Debug::print_bb();
    // MoveGen::init_MoveGen();
    // Debug::print_bb(BitBoard(0x00'00'01'00'00'00'00'00));
    // Debug::print_bb(BitBoard(0x00'00'00'02'00'00'00'00));
    // MoveGen::BLACK_PIECES = 0x00'00'01'00'00'00'00'00;
    // Debug::print_bb(MoveGen::BLACK_PIECES);
    // std::cout << __builtin_ctzll(MoveGen::BLACK_PIECES) << std::endl;
    
    // std::vector<Move> PossibleMoves = MoveGen::white_pawn_moves(BitBoard(0x00'00'00'02'00'00'00'00),BitBoard(0x00'00'01'00'00'00'00'00));
    // for (const Move& i : PossibleMoves)
    // {
    //     Debug::print_encoded_move_str(i);
    // }
    
    // BoardState curState;
    // curState.fen_importer("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
    // Debug::print_entire_board(curState.curBoards);
    // curState.curBoards.update_full_board();
    // Debug::print_bb(curState.curBoards.TESTING_ALL_BOARD);
    Testing::RunTests();

    return 0;
}
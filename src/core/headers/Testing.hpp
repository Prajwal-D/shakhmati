#ifndef TESTING_HPP
#define TESTING_HPP

#include <cassert>
#include <iostream>

#include "BitBoard.hpp"
#include "MoveGen.hpp"
#include "Move.hpp"
#include "Debug.hpp"

//white pawn move gen tests
#define TESTFEN1 "8/8/8/4pP2/8/8/8/8 w - - 0 1"     //checks en passant
#define TESTFEN2 "8/8/8/8/2p5/8/2P5/8 w - - 0 1"    //checks obsticle in way of double move - single move should still work
#define TESTFEN3 "p7/k7/P7/8/8/8/8/8 w - - 0 1"     //checks with obsticles in way of all moves- should produce no moves returned
#define TESTFEN4 "8/8/3qp3/4P3/8/8/8/8 w - - 0 1"   //checks left capture with no other possible moves
#define TESTFEN5 "8/8/8/8/8/8/rb6/Pr6 w - - 0 1"    //checks right capture with no other possible moves
#define TESTFEN6 "8/8/8/8/8/8/r7/Pr6 w - - 0 1"     //checks another position with no possible moves
#define TESTFEN7 "8/8/8/qq6/P1q1q3/4P1q1/2P3PP/8 w - - 0 1" //complicated position with lots of possible moves
#define TESTFEN8 "8/8/2p1kPp1/6P1/4K3/8/8/8 w - - 0 1" //pawn endgame with 1 possible pawn move for white 
#define TESTFEN9 "R7/P5k1/8/8/8/6P1/6K1/r7 w - - 0 1" //another pawn endgame with 1 possible pawn moves for white
#define TESTFEN10 "rnbq1rk1/pp2ppbp/6p1/2pp4/2PPnB2/2N1PN2/PP3PPP/R2QKB1R w KQ - 0 8" //very complicated position taken from queens gambit opening with many possible white pawn moves
  
//black pawn move gen tests
#define TESTFEN11 "8/5p2/8/8/8/8/8/8 w - - 0 1"

#define RUN_MOVE_GEN_TEST(testNum, moveVec1, moveVec2)      std::cout <<  "Test number " << (testNum) << " has " << (((moveVec1) == (moveVec2)) ? "PASSED" : "FAILED") << std::endl; \
                                                            if(!((moveVec1) == (moveVec2))) \
                                                            { \
                                                                std::cout << "\nTest " << (testNum) << " contents: " << std::endl;\
                                                                std::cout << "Move vector 1 contents: " << std::endl; \
                                                                for(const Move& i : moveVec1){ Debug::print_encoded_move_str(i); std::cout << std::endl;} \
                                                                std::cout << "\nMove vector 2 contents: " << std::endl; \
                                                                for(const Move& i : moveVec2){ Debug::print_encoded_move_str(i); std::cout << std::endl;}; \
                                                            }

#define SHORTEND_MOVE_GEN_TEST(testNum, fen, moveVec1, moveVec2)    instance = BoardState(); \
                                                                    instance.fen_importer((fen)); \
                                                                    MoveGen::update_constants(instance.curBoard); \
                                                                    RUN_MOVE_GEN_TEST((testNum),(moveVec1),(moveVec2))
namespace Testing
{
    void RunTests()
    {
        MoveGen::init_MoveGen();
        BoardState instance;

        SHORTEND_MOVE_GEN_TEST
        (
            1, //Test number
            TESTFEN1, //Positon to load (fen)
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0x2C)), //move generated
            std::vector<Move> // expected moves generated
                ({
                    Moves::encode_move(0x25,0x2C,Magics::PAWN,1),
                    Moves::encode_move(0x25,0x2D,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            2,
            TESTFEN2,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x0A,0x12,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            3,
            TESTFEN3,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>({})
        );
        SHORTEND_MOVE_GEN_TEST
        (
            4,
            TESTFEN4,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x24,0x2B,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            5,
            TESTFEN5,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x00,0x09,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            6,
            TESTFEN6,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>({})
        );
        SHORTEND_MOVE_GEN_TEST
        (
            7,
            TESTFEN7,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x18,0x21,Magics::PAWN,1),
                    Moves::encode_move(0x0A,0x12,Magics::PAWN,1),
                    Moves::encode_move(0x0F,0x16,Magics::PAWN,1),
                    Moves::encode_move(0x0F,0x17,Magics::PAWN,1),
                    Moves::encode_move(0x0F,0x1F,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            8,
            TESTFEN8,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x2D,0x35,Magics::PAWN,1),
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            9,
            TESTFEN9,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x16,0x1E,Magics::PAWN,1),
                })
        );      
        SHORTEND_MOVE_GEN_TEST
        (
            10,
            TESTFEN10,
            MoveGen::white_pawn_moves(instance.curBoard.whitePawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x08,0x10,Magics::PAWN,1),
                    Moves::encode_move(0x08,0x18,Magics::PAWN,1),
                    Moves::encode_move(0x09,0x11,Magics::PAWN,1),
                    Moves::encode_move(0x09,0x19,Magics::PAWN,1),
                    Moves::encode_move(0x1A,0x23,Magics::PAWN,1),
                    Moves::encode_move(0x1B,0x22,Magics::PAWN,1),
                    Moves::encode_move(0x0E,0x16,Magics::PAWN,1),
                    Moves::encode_move(0x0E,0x1E,Magics::PAWN,1),
                    Moves::encode_move(0x0F,0x17,Magics::PAWN,1),
                    Moves::encode_move(0x0F,0x1F,Magics::PAWN,1)
                })
        );
        SHORTEND_MOVE_GEN_TEST
        (
            11,
            TESTFEN11,
            MoveGen::black_pawn_moves(instance.curBoard.blackPawns,index_to_bb(0)),
            std::vector<Move>
                ({
                    Moves::encode_move(0x35,0x2D,Magics::PAWN,0),
                    Moves::encode_move(0x35,0x25,Magics::PAWN,0)
                })
        );
    }
}
#endif
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdint>

typedef uint64_t BitBoard;

struct AllBoards
{
    constexpr AllBoards()
    :whiteKings(0ull), whiteQueens(0ull), whiteRooks(0ull), whiteBishops(0ull), whiteKnights(0ull), whitePawns(0ull),
    blackKings(0ull), blackQueens(0ull), blackRooks(0ull), blackBishops(0ull), blackKnights(0ull), blackPawns(0ull)
    {}
    BitBoard whiteKings;
    BitBoard whiteQueens;
    BitBoard whiteRooks;
    BitBoard whiteBishops;
    BitBoard whiteKnights;
    BitBoard whitePawns;

    BitBoard blackKings;
    BitBoard blackQueens;
    BitBoard blackRooks;
    BitBoard blackBishops;
    BitBoard blackKnights;
    BitBoard blackPawns;

};

struct FullBoard
{
    FullBoard()
    :curBoard(),castling(0x0F)
    {};

    AllBoards curBoard;
    uint8_t castling; //initialised as 0000 1111, where top 4 bits are ignored
                      //1111 goes left to right as white king-side, white queen-side, black king-side, black queen-side
    


    
};



#endif
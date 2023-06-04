#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdint>
#include <string_view>
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>

typedef uint64_t BitBoard;
#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

template<typename T>
constexpr BitBoard index_to_bb(T index){return 1ull << static_cast<unsigned>(index);}

struct AllBoards
{
    constexpr AllBoards():
    whiteKings(0ull), whiteQueens(0ull), whiteRooks(0ull), whiteBishops(0ull), whiteKnights(0ull), whitePawns(0ull),
    blackKings(0ull), blackQueens(0ull), blackRooks(0ull), blackBishops(0ull), blackKnights(0ull), blackPawns(0ull),
    TESTING_ALL_BOARD(0ull)
    {}
    void update_full_board();
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

    BitBoard TESTING_ALL_BOARD;

};

struct BoardState
{
    BoardState():
    curBoard(),castling(0x0F),whiteTurn(true), halfMoves(0)
    {};
    //You should add [[nodiscard]] specifier to this function 
    std::vector<std::string> split(const std::string &stringToSplit, char delim);
    //I have discovered an issue with the fen_importer, if i load 2 FENs, it will keep the previous board state and or the
    //new board positions ontop. you should reset board values before writing the new fen data to board
    bool fen_importer(std::string fen);
    

    AllBoards curBoard;
    uint8_t castling; //initialised as 0000 1111, where top 4 bits are ignored
                      //1111 goes left to right as white king-side, white queen-side, black king-side, black queen-side
    bool whiteTurn;
    int halfMoves;
    BitBoard enPassant;
    
};

#endif
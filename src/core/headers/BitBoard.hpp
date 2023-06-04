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
    constexpr BoardState():
    currentBoards(),castling(0x00),whiteTurn(true), halfMoves(0), enPassant(0ull)
    {};
    [[nodiscard]] std::vector<std::string> split(const std::string &stringToSplit, char delim);
    int fen_importer(std::string fen);
    constexpr void reset_board();
    

    AllBoards currentBoards;
    uint8_t castling; //initialised as 0000 0000, where top 4 bits are ignored
                      //1111 goes left to right as white king-side, white queen-side, black king-side, black queen-side
    bool whiteTurn;
    int halfMoves;
    BitBoard enPassant;
    
};

#endif
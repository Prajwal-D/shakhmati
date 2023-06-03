#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdint>
#include <string_view>

typedef uint64_t BitBoard;
#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
struct AllBoards
{
    constexpr AllBoards():
    whiteKings(0ull), whiteQueens(0ull), whiteRooks(0ull), whiteBishops(0ull), whiteKnights(0ull), whitePawns(0ull),
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
enum class EnPassanting:BitBoard
{
    A3 = 0x0000'1000'0000'0000,
    B3 = A3 >> 1,
    C3 = B3 >> 1,
    D3 = C3 >> 1,
    E3 = D3 >> 1,
    F3 = E3 >> 1,
    G3 = F3 >> 1,
    H3 = G3 >> 1,

    A6 = 0x0000'0000'0000'0000,

};

struct BoardState
{
    BoardState():
    curBoard(),castling(0x0F),whiteTurn(true), halfMoves(0)
    {};
    //You should add [[nodiscard]] specifier to this function 
    bool fen_importer(std::string_view fen);

    AllBoards curBoard;
    uint8_t castling; //initialised as 0000 1111, where top 4 bits are ignored
                      //1111 goes left to right as white king-side, white queen-side, black king-side, black queen-side
    bool whiteTurn;
    int halfMoves;
    BitBoard enPassant;
    // TODO implement enpassant

    
};

#endif
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <cstdint>
#include <string_view>
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cassert>
#include "MagicConstants.hpp"

struct AllBoards
{
    constexpr AllBoards():
    white_kings_(0ull), white_queens_(0ull), white_rooks_(0ull), white_bishops_(0ull), white_knights_(0ull), white_pawns_(0ull),
    black_kings_(0ull), black_queens_(0ull), black_rooks_(0ull), black_bishops_(0ull), black_knights_(0ull), black_pawns_(0ull),
    TESTING_ALL_BOARD(0ull){}

    void UpdateFullBoard();
    BitBoard white_kings_;
    BitBoard white_queens_;
    BitBoard white_rooks_;
    BitBoard white_bishops_;
    BitBoard white_knights_;
    BitBoard white_pawns_;

    BitBoard black_kings_;
    BitBoard black_queens_;
    BitBoard black_rooks_;
    BitBoard black_bishops_;
    BitBoard black_knights_;
    BitBoard black_pawns_;

    BitBoard TESTING_ALL_BOARD;

};

struct BoardState
{
    constexpr BoardState():
    piece_boards_(),castling_(0x00),white_turn_(true), half_moves_(0), en_passant_(0ull)   {};

    [[nodiscard]] std::vector<std::string> Split(const std::string &stringToSplit, char delim);
    int FenImporter(std::string fen);
    constexpr void ResetBoard();
    

    AllBoards piece_boards_;
    uint8_t castling_; //initialised as 0000 0000, where top 4 bits are ignored
                      //1111 goes left to right as white king-side, white queen-side, black king-side, black queen-side
    bool white_turn_;
    int half_moves_;
    BitBoard en_passant_;
    
};

#endif
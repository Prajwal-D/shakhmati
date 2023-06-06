#ifndef DEBUG_HPP
#define DEBUG_HPP
#include "BitBoard.hpp"
#include <vector>
#include <string_view>
#include <iostream>
#include <bitset>
#include "Move.hpp"
namespace Debug
{
    void PrintBB(BitBoard board, int board_center,bool mirrored=true)
    {
        std::string output{},someLine{};
        for(int row{0}; row < 8; ++row)
        {
            for(int col{0}; col < 8;++col)
            {
                if((col + row*8) == board_center)
                {
                    someLine = mirrored ?   someLine + "X " : "X " + someLine;
                }
                else if(((board >> (col + row*8)))&1ull)
                {
                    someLine = mirrored ?   someLine + "1 " : "1 " + someLine ;
                }
                else
                {
                    someLine = mirrored ?   someLine + "0 " : "0 " + someLine;
                }
            }
            someLine += "|" + std::to_string(row + 1) + " \n";
            output = someLine + output;
            someLine = "";
        }                    
        output += "----------------\n";
        output += mirrored ? "A B C D E F G H" : "H G F E D C B A";
        std::cout << output << std::endl;
    }
    void PrintBB(BitBoard board, bool mirrored=true)
    {
        std::string output{},someLine{};
        for(int row{0}; row < 8; ++row)
        {
            for(int col{0}; col < 8;++col)
            {
                if(((board >> (col + row*8)))&1ull)
                {
                    someLine = mirrored ?   someLine + "1 " : "1 " + someLine;
                }
                else
                {
                    someLine = mirrored ?   someLine + "0 " : "0 " + someLine;
                }
            }
            someLine += "|" + std::to_string(row + 1) + " \n";
            output = someLine + output;
            someLine = "";
        }                    
        output += "----------------\n";
        output += mirrored ? "A B C D E F G H" : "H G F E D C B A";
        std::cout << output << std::endl;
    }
    void PrintEntireBoard(const AllBoards& board)
    {
        std::cout << "wk" << std::endl;
        PrintBB(board.white_kings_,true);
        std::cout << "wq" << std::endl;
        PrintBB(board.white_queens_,true);
        std::cout << "wb" << std::endl;
        PrintBB(board.white_bishops_,true);
        std::cout << "wn" << std::endl;
        PrintBB(board.white_knights_,true);
        std::cout << "wr" << std::endl;
        PrintBB(board.white_rooks_,true);
        std::cout << "wp" << std::endl;
        PrintBB(board.white_pawns_,true);

        std::cout << "bk" << std::endl;
        PrintBB(board.black_kings_,true);
        std::cout << "bq" << std::endl;
        PrintBB(board.black_queens_,true);
        std::cout << "bb" << std::endl;
        PrintBB(board.black_bishops_,true);
        std::cout << "bn" << std::endl;
        PrintBB(board.black_knights_,true);
        std::cout << "br" << std::endl;
        PrintBB(board.black_rooks_,true);
        std::cout << "bp" << std::endl;
        PrintBB(board.black_pawns_,true);
    }
    std::string PieceTypeToStr(PieceType piece)
    {
        switch (piece)
        {
        case Magics::KING:
            return "King";
        case Magics::QUEEN:
            return "Queen";
        case Magics::BISHOP:
            return "Bishop";
        case Magics::KNIGHT:
            return "Knight";
        case Magics::ROOK:
            return "Rook";
        case Magics::PAWN:
            return "Pawn";
        default:
            return "Error with piece type to string";
        }
    }
    void PrintEncodedMoveStr(Move move)
    {
        std::string move_str{""};
        move_str += "The start index is: " + std::to_string(move & Magics::START_SQ_MASK) + "\n";
        move_str += "The end index is: " + std::to_string((move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT) + "\n";
        move_str += "THe piece moved was: " + PieceTypeToStr((move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT) + "\n";
        move_str += (((move & Magics::COLOUR_MASK) >> Magics::COLOUR_SHIFT) == 1) ? "The piece was white" : "The piece was black";
        std::cout << move_str;
    }
    void ShortPrintEncodedMoveStr(Move move)
    {
        std::string move_str{""};
        move_str += "S: " + std::to_string(move & Magics::START_SQ_MASK) + ", ";
        move_str += "E: " + std::to_string((move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT) + ", ";
        move_str += "T: " + PieceTypeToStr((move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT) + ", ";
        move_str += "C: " + (((move & Magics::COLOUR_MASK) >> Magics::COLOUR_SHIFT) == 1) ? "W" : "B";
        std::cout << move_str;
    }
    void PrintEncodedMoveBin(Move move)
    {
        std::cout << std::bitset<16>(move) << std::endl;
    }
}
#endif
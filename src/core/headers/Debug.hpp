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
    void print_bb(BitBoard board, int board_center,bool mirrored=true)
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
    void print_bb(BitBoard board, bool mirrored=true)
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
    void print_entire_board(const AllBoards& board)
    {
        std::cout << "wk" << std::endl;
        print_bb(board.whiteKings,true);
        std::cout << "wq" << std::endl;
        print_bb(board.whiteQueens,true);
        std::cout << "wb" << std::endl;
        print_bb(board.whiteBishops,true);
        std::cout << "wn" << std::endl;
        print_bb(board.whiteKnights,true);
        std::cout << "wr" << std::endl;
        print_bb(board.whiteRooks,true);
        std::cout << "wp" << std::endl;
        print_bb(board.whitePawns,true);

        std::cout << "bk" << std::endl;
        print_bb(board.blackKings,true);
        std::cout << "bq" << std::endl;
        print_bb(board.blackQueens,true);
        std::cout << "bb" << std::endl;
        print_bb(board.blackBishops,true);
        std::cout << "bn" << std::endl;
        print_bb(board.blackKnights,true);
        std::cout << "br" << std::endl;
        print_bb(board.blackRooks,true);
        std::cout << "bp" << std::endl;
        print_bb(board.blackPawns,true);
    }
    std::string piece_type_to_str(PieceType piece)
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
    void print_encoded_move_str(Move move)
    {
        std::string move_str{""};
        move_str += "The start index is: " + std::to_string(move & Magics::START_SQ_MASK) + "\n";
        move_str += "The end index is: " + std::to_string((move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT) + "\n";
        move_str += "THe piece moved was: " + piece_type_to_str((move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT) + "\n";
        move_str += (((move & Magics::COLOUR_MASK) >> Magics::COLOUR_SHIFT) == 1) ? "The piece was white" : "The piece was black";
        std::cout << move_str;
    }
    void short_print_encoded_move_str(Move move)
    {
        std::string move_str{""};
        move_str += "S: " + std::to_string(move & Magics::START_SQ_MASK) + ", ";
        move_str += "E: " + std::to_string((move & Magics::END_SQ_MASK) >> Magics::END_SQ_SHIFT) + ", ";
        move_str += "T: " + piece_type_to_str((move & Magics::PIECE_TYPE_MASK) >> Magics::PIECE_TYPE_SHIFT) + ", ";
        move_str += "C: " + (((move & Magics::COLOUR_MASK) >> Magics::COLOUR_SHIFT) == 1) ? "W" : "B";
        std::cout << move_str;
    }
    void print_encoded_move_bin(Move move)
    {
        std::cout << std::bitset<16>(move) << std::endl;
    }
}
#endif
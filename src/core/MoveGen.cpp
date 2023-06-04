#include "headers/MoveGen.hpp"

void MoveGen::init_MoveGen()
{
    WHITE_PIECES = 0ull;
    BLACK_PIECES = 0ull;
    EMPTY = ~WHITE_PIECES;
}
void MoveGen::update_constants(const AllBoards& b)
{
    WHITE_PIECES = b.whiteKings | b.whiteQueens | b.whiteBishops | b.whiteKnights | b.whiteRooks | b.whitePawns;
    BLACK_PIECES = b.blackKings | b.blackQueens | b.blackBishops | b.blackKnights | b.blackRooks | b.blackPawns;
    EMPTY = ~(WHITE_PIECES | BLACK_PIECES);
}
std::vector<Move> MoveGen::white_pawn_moves(BitBoard pawns,BitBoard en_passant_target_sq)
{
    std::vector<Move> possible_moves{};
    BitBoard pawn_move{0};
    const BitBoard black_pieces_copy = BLACK_PIECES | en_passant_target_sq;

    //generating 1 sq forward moves
    pawn_move = (pawns << 8) & EMPTY; 
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-8),index,Magics::PAWN,1));
        }
    }
    //generating 2 sq forawrd moves
    pawn_move = (pawns << 16) & EMPTY & (EMPTY << 8) & Magics::RANK_4; 
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-16),index,Magics::PAWN,1));
        }
    }
    //generating all left capturing moves
    pawn_move = (pawns << 7) & black_pieces_copy & ~Magics::FILE_H;
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-7),index,Magics::PAWN,1));
        }
    }
    //generating all the right capturing moves
    pawn_move = (pawns << 9) & black_pieces_copy & ~Magics::FILE_A;
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-9),index,Magics::PAWN,1));
        }
    }
    return possible_moves;
}
std::vector<Move> MoveGen::black_pawn_moves(BitBoard pawns,BitBoard en_passant_target_sq)
{
    std::vector<Move> possible_moves{};
    BitBoard pawn_move{0};
    const BitBoard white_pieces_copy = WHITE_PIECES | en_passant_target_sq;

    //generating 1 sq forward moves
    pawn_move = (pawns >> 8) & EMPTY; 
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        //std::cout << "here\n" << std::endl;
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-8),index,Magics::PAWN,0));
        }
    }
    //generating 2 sq forawrd moves
    pawn_move = (pawns >> 16) & EMPTY & (EMPTY >> 8) & Magics::RANK_5; 
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-16),index,Magics::PAWN,0));
        }
    }
    //generating all right capturing moves(right capturing from white's perspective)
    pawn_move = (pawns >> 7) & white_pieces_copy & ~Magics::FILE_A;
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-7),index,Magics::PAWN,0));
        }
    }
    //generating all the left capturing moves
    pawn_move = (pawns >> 9) & white_pieces_copy & ~Magics::FILE_H;
    for(int index = __builtin_ctzll(pawns);index< 64;++index)
    {
        if ((pawn_move >> index) & 1)
        {
            possible_moves.push_back(Moves::encode_move((index-9),index,Magics::PAWN,0));
        }
    }
    return possible_moves;
}
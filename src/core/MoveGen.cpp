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
        //generating all right capturing moves
        pawn_move = (pawns << 7) & BLACK_PIECES & ~Magics::FILE_H;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if ((pawn_move >> index) & 1)
            {
                possible_moves.push_back(Moves::encode_move((index-7),index,Magics::PAWN,1));
            }
        }
        //generating all the left capturing moves
        pawn_move = (pawns << 9) & BLACK_PIECES & ~Magics::FILE_A;
        for(int index = __builtin_ctzll(pawns);index< 64;++index)
        {
            if ((pawn_move >> index) & 1)
            {
                possible_moves.push_back(Moves::encode_move((index-9),index,Magics::PAWN,1));
            }
        }
        //generating the en_passant_move
        if(en_passant_target_sq == -1)
            return possible_moves;
        pawn_move = ((pawns << 9) & ~Magics::FILE_A);
        pawn_move &= 1ull << en_passant_target_sq;
        if(pawn_move)
        {
            const int en_passant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_passant_index-9,en_passant_index,Magics::PAWN,1));
            return possible_moves;
        }
        pawn_move = ((pawns << 7) & ~Magics::FILE_H);
        pawn_move &= 1ull << en_passant_target_sq;
        if(pawn_move)
        {
            const int en_passant_index = __builtin_ctzll(pawn_move);
            possible_moves.push_back(Moves::encode_move(en_passant_index-7,en_passant_index,Magics::PAWN,1));
        }
        return possible_moves;
    }
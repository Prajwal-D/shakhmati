#include "headers/BitBoard.hpp"

std::vector<std::string> BoardState::Split(const std::string &stringToSplit, char delim) 
{
    std::vector<std::string> result;
    std::stringstream ss (stringToSplit);
    std::string item;

    while (getline(ss, item, delim)) 
    {
        result.push_back(item);
    }
    return result;
}   
constexpr void BoardState::ResetBoard()
{
    piece_boards_ = AllBoards();
    castling_ = 0x00;
    white_turn_ = true;
    half_moves_ = 0;
    en_passant_ = 0;
}
int BoardState::FenImporter(std::string fen)
{
    ResetBoard();

    std::vector<std::string> fenSections = Split(fen, ' ');  
    std::vector<std::string> rankSections;
    try
    {
        rankSections = Split(fenSections.at(0), '/');
    }
    catch(std::out_of_range& oor)
    {
        std::cout << "Invalid fen! \n";
        return -1;
    }

    int curRank = 7;
    for (const std::string& i:rankSections)
    {
        int curPosInString = 0;
        int curFile = 0;
        
        while(curPosInString < i.size())
        {
            char curChar = i.at(curPosInString);
            if(std::isdigit(curChar))
            {
                curFile += (curChar - '0') - 1;
            }
            else
            {
                switch (curChar)
                {
                case('p'):
                    piece_boards_.black_pawns_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('n'):
                    piece_boards_.black_knights_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('b'):
                    piece_boards_.black_bishops_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('r'):
                    piece_boards_.black_rooks_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('q'):
                    piece_boards_.black_queens_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('k'):
                    piece_boards_.black_kings_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('P'):
                    piece_boards_.white_pawns_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('N'):
                    piece_boards_.white_knights_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('B'):
                    piece_boards_.white_bishops_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('R'):
                    piece_boards_.white_rooks_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('Q'):
                    piece_boards_.white_queens_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('K'):
                    piece_boards_.white_kings_ |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                default:
                    return -1;
                }
            } 
            curPosInString++;
            curFile++;
        }
        curRank--;  
    }

    switch (fenSections.at(1).at(0))
    {
    case('w'):
        white_turn_ = true;
        break;
    case('b'):
        white_turn_ = false;
        break;
    default:
        return -1;
    }

    for(char i:fenSections.at(2))
    {
        switch (i)
        {
        case '-':
            break;
        case 'K':
            castling_ |= 0x08;
            break;
        case 'Q':
            castling_ |= 0x04;
            break;
        case 'k':
            castling_ |= 0x02;
            break;
        case 'q':
            castling_ |= 0x01;
            break; 
        default:
            return -1;
        }
    }
    if(fenSections.at(3) != "-")
    {
        assert((static_cast<int>(fenSections.at(3).at(0)) > 96 && static_cast<int>(fenSections.at(3).at(0)) < 105));
        assert((static_cast<int>(fenSections.at(3).at(1)) == 51 || static_cast<int>(fenSections.at(3).at(1)) == 54));
        int enPassantIndex = 0;
        enPassantIndex += (fenSections.at(3).at(0)) - 97;
        enPassantIndex += ((fenSections.at(3).at(1) - 48) - 1) * 8;
        en_passant_ = BitBoard(1) << enPassantIndex;
    }

    half_moves_ = std::stoi(fenSections.at(4));
    return std::stoi(fenSections.at(5));
};

void AllBoards::UpdateFullBoard()
{
    TESTING_ALL_BOARD = white_kings_ | white_queens_ | white_bishops_ | white_knights_ | white_rooks_ | white_pawns_ | black_kings_ | black_queens_ | black_bishops_ | black_knights_ | black_rooks_ | black_pawns_;
}

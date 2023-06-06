#include "headers/BitBoard.hpp"

std::vector<std::string> BoardState::Split(const std::string& str_to_split, char delim) 
{
    std::vector<std::string> result;
    std::stringstream ss (str_to_split);
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

    std::vector<std::string> fen_sections = Split(fen, ' ');  
    std::vector<std::string> rank_sections;
    try
    {
        rank_sections = Split(fen_sections.at(0), '/');
    }
    catch(std::out_of_range& oor)
    {
        std::cout << "Invalid fen! \n";
        return -1;
    }

    int current_rank = 7;
    for (const std::string& i:rank_sections)
    {
        int pos_in_str = 0;
        int current_file = 0;
        
        while(static_cast<std::size_t>(pos_in_str) < i.size())
        {
            char current_char = i.at(pos_in_str);
            if(std::isdigit(current_char))
            {
                current_file += (current_char - '0') - 1;
            }
            else
            {
                switch (current_char)
                {
                case('p'):
                    piece_boards_.black_pawns_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('n'):
                    piece_boards_.black_knights_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('b'):
                    piece_boards_.black_bishops_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('r'):
                    piece_boards_.black_rooks_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('q'):
                    piece_boards_.black_queens_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('k'):
                    piece_boards_.black_kings_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('P'):
                    piece_boards_.white_pawns_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('N'):
                    piece_boards_.white_knights_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('B'):
                    piece_boards_.white_bishops_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('R'):
                    piece_boards_.white_rooks_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('Q'):
                    piece_boards_.white_queens_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                case('K'):
                    piece_boards_.white_kings_ |= BitBoard(1) << ((current_rank * 8) + current_file);
                    break;
                default:
                    return -1;
                }
            } 
            pos_in_str++;
            current_file++;
        }
        current_rank--;  
    }

    switch (fen_sections.at(1).at(0))
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

    for(const char i:fen_sections.at(2))
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
    if(fen_sections.at(3) != "-")
    {
        assert((static_cast<int>(fen_sections.at(3).at(0)) > 96 && static_cast<int>(fen_sections.at(3).at(0)) < 105));
        assert((static_cast<int>(fen_sections.at(3).at(1)) == 51 || static_cast<int>(fen_sections.at(3).at(1)) == 54));
        int en_passant_index = 0;
        en_passant_index += (fen_sections.at(3).at(0)) - 97;
        en_passant_index += ((fen_sections.at(3).at(1) - 48) - 1) * 8;
        en_passant_ = BitBoard(1) << en_passant_index;
    }

    half_moves_ = std::stoi(fen_sections.at(4));
    return std::stoi(fen_sections.at(5));
};

void AllBoards::UpdateFullBoard()
{
    TESTING_ALL_BOARD = white_kings_ | white_queens_ | white_bishops_ | white_knights_ | white_rooks_ | white_pawns_ | black_kings_ | black_queens_ | black_bishops_ | black_knights_ | black_rooks_ | black_pawns_;
}

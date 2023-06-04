#include "headers/BitBoard.hpp"

std::vector<std::string> BoardState::split(const std::string &stringToSplit, char delim) 
{
    std::vector<std::string> result;
    std::stringstream ss (stringToSplit);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}   

void BoardState::reset_board(){
    currentBoards = AllBoards();
    castling = 0x00;
    whiteTurn = true;
    halfMoves = 0;
    
}

bool BoardState::fen_importer(std::string fen){
    
    reset_board();

    std::vector<std::string> fenSections = split(fen, ' ');  
    std::vector<std::string> rankSections;
    try{
        rankSections = split(fenSections.at(0), '/');
    }
    catch(std::out_of_range& oor){
        std::cout << "Invalid fen! \n";
        return false;
    }

    int curRank = 7;
    for (std::string i:rankSections)
    {
        int curPosInString = 0;
        int curFile = 0;
        
        while(curPosInString < i.size()){
            char curChar = i.at(curPosInString);
            if(std::isdigit(curChar)){
                curFile += (curChar - '0') - 1;
            }
            else{
                switch (curChar){
                case('p'):
                    currentBoards.blackPawns |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('n'):
                    currentBoards.blackKnights |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('b'):
                    currentBoards.blackBishops |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('r'):
                    currentBoards.blackRooks |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('q'):
                    currentBoards.blackQueens |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('k'):
                    currentBoards.blackKings |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('P'):
                    currentBoards.whitePawns |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('N'):
                    currentBoards.whiteKnights |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('B'):
                    currentBoards.whiteBishops |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('R'):
                    currentBoards.whiteRooks |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('Q'):
                    currentBoards.whiteQueens |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('K'):
                    currentBoards.whiteKings |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                default:
                    return false;
                }
            } 
            curPosInString++;
            curFile++;
        }
        curRank--;  
    }
    
        
    return true;

};

void AllBoards::update_full_board()
{
    TESTING_ALL_BOARD = whiteKings | whiteQueens | whiteBishops | whiteKnights | whiteRooks | whitePawns | blackKings | blackQueens | blackBishops | blackKnights | blackRooks | blackPawns;
}

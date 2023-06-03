#include "headers/BitBoard.hpp"

std::vector<std::string> BoardState::split(const std::string &stringToSplit, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (stringToSplit);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}   

bool BoardState::fen_importer(std::string fen)
{
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
                    curBoard.blackPawns |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('n'):
                    curBoard.blackKnights |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('b'):
                    curBoard.blackBishops |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('r'):
                    curBoard.blackRooks |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('q'):
                    curBoard.blackQueens |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('k'):
                    curBoard.blackKings |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('P'):
                    curBoard.whitePawns |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('N'):
                    curBoard.whiteKnights |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('B'):
                    curBoard.whiteBishops |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('R'):
                    curBoard.whiteRooks |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('Q'):
                    curBoard.whiteQueens |= BitBoard(1) << ((curRank * 8) + curFile);
                    break;
                case('K'):
                    curBoard.whiteKings |= BitBoard(1) << ((curRank * 8) + curFile);
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

void AllBoards::update_full_board(){
    TESTING_ALL_BOARD = whiteKings | whiteQueens | whiteBishops | whiteKnights | whiteRooks | whitePawns | blackKings | blackQueens | blackBishops | blackKnights | blackRooks | blackPawns;
}

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

    int curRank = 8;
    for (std::string i:rankSections)
    {
      int curPosInString = 0;
      int curFile = 0;
      while(curPosInString < i.size()){
        char curChar = i.at(curPosInString);
        if(std::isdigit(curChar)){
            curFile += (curChar - '0') - 1;
        } 
        
        curPosInString++;
        curFile++;
      }  
    }
    
    
    return true;

};

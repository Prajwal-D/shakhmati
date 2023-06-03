#ifndef MOVE_HPP
#define MOVE_HPP
#include <cstdint>

//The moves will be stored as index of the combined board to another index of the combinbed board
struct Move
{
    Move()=delete;
    explicit Move(uint8_t start,uint8_t target): startingSquare(startingSquare),targetSqaure(target){}
    const uint8_t startingSquare;
    const uint8_t targetSqaure;
};
#endif
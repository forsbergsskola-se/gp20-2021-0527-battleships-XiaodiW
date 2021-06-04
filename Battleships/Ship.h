//
// Created by Xiaodi Wang on 2021-06-04.
//

#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H
struct Ship{
    int size{};
    int headPosition[2]{};
    int direction{};
    int hits{};
    bool sunk{};
    explicit Ship(int size){
        this->size = size;
        hits = 0;
        sunk = false;
    }
    Ship()= default;
};
#endif //BATTLESHIPS_SHIP_H

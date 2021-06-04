#include <iostream>
using namespace std;
struct Ship{
    int size;
    int headPosition[2]{};
    int direction{};
    explicit Ship(int size){
        this->size = size;
    }
};
const int size = 10;
bool GenerateShip(int);
void GenerateMap();
bool ValidLocation(int[2]);
void PrintMap();
void Attack();
int map[size][size] = {0};
Ship ships[] = {Ship(5),Ship(5),Ship(4),Ship(4),Ship(3),Ship(3),Ship(2),Ship(2)};
Ship templateShip(5);
int main() {
    GenerateMap();
    PrintMap();
    Attack();
    return 0;
}

bool GenerateShip(int shipSize){
    srand(time(0));
    int tempMap[size][size];
    for (auto & i : tempMap)
        for (int & j : i)
            j = 0;
    Head:
    int sum = 0;
    for (auto & i : tempMap)
        for (int j : i)
            sum += j;
    if(sum >= size * size) return false;
    int head[2];
    head[0] = rand() % 10;
    head[1] = rand() % 10;
    tempMap[head[0]][head[1]] = 1;
    if(ValidLocation(head)) {
        templateShip.headPosition[0] = head[0];
        templateShip.headPosition[1] = head[1];
    }
    else goto Head;
    int directionArray[4] = {1,1,1,1};
    Body:
    int sum1 = 0;
    for (int i : directionArray)
        sum1 += i;
    if(sum1 == 0) goto Head;
    int direction = rand() % 4;
    if(directionArray[direction] == 0) goto Body;
    directionArray[direction] = 0;
    switch (direction) {
        case 0:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip.headPosition[0] - i, templateShip.headPosition[1]};
                if(newLocation[0] < 0 || !ValidLocation(newLocation))
                    goto Body;
            }
            templateShip.direction = 0;
        break;
        case 1:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip.headPosition[0] + i, templateShip.headPosition[1]};
                if(newLocation[0] >= shipSize || !ValidLocation(newLocation))
                    goto Body;
            }
            templateShip.direction = 1;
        break;
        case 2:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip.headPosition[0], templateShip.headPosition[1] - i};
                if(newLocation[1] < 0 || !ValidLocation(newLocation))
                    goto Body;
            }
            templateShip.direction = 2;
        break;
        case 3:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip.headPosition[0], templateShip.headPosition[1] + i};
                if(newLocation[1] >= shipSize || !ValidLocation(newLocation))
                    goto Body;
            }
            templateShip.direction = 3;
        break;
        default :
            goto Body;
    }
    return true;
};

bool ValidLocation(int location[2]){
    if(map[location[0]][location[1]] != 0) return false;
    if(location[0] - 1 >= 0)
        if(map[location[0] - 1][location[1]] != 0) return false;
    if(location[0] + 1 < size)
        if(map[location[0] + 1][location[1]] != 0) return false;
    if(location[1] - 1 >= 0)
        if(map[location[0]][location[1] - 1] != 0) return false;
    if(location[1] + 1 < size)
        if(map[location[0]][location[1] + 1] != 0) return false;
    return true;
}
void GenerateMap(){
    for (auto & ship : ships) {
        int shipSize = ship.size;
        if(!GenerateShip(shipSize)) return;
        ship = templateShip;
        map[ship.headPosition[0]][ship.headPosition[1]] = 1;
        switch (templateShip.direction) {
            case 0:
                for (int i = 1; i < shipSize; ++i)
                    map[ship.headPosition[0] - i][ship.headPosition[1]] = 1;
                break;
            case 1:
                for (int i = 1; i < shipSize; ++i)
                    map[ship.headPosition[0] + i][ship.headPosition[1]] = 1;
                break;
            case 2:
                for (int i = 1; i < shipSize; ++i)
                    map[ship.headPosition[0]][ship.headPosition[1] - i] = 1;
                break;
            case 3:
                for (int i = 1; i < shipSize; ++i)
                    map[ship.headPosition[0]][ship.headPosition[1] + i] = 1;
                break;
            default :
                return;
        }
    }
}
void PrintMap(){
    cout << "  A B C D E F G H I J"<< endl;
    int x = 0;
    for (auto & i : map) {
        cout << x ++ << " ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void Attack(){
    cout << "Which Point you want to attack? i.e. B3" << endl;
    char input[3];
    cin.getline(input,3);
    int x = tolower(input[0], locale()) ;
    x -= 97;
    int y = input[1] -48;
    cout << "x: " << x << "  y:" << y << endl;
}

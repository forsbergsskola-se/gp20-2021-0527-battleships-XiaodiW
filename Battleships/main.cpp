#include <iostream>
using namespace std;
const int size = 10;
bool GenerateShip(int);
void GenerateMap();
bool ValidLocation(int[2]);
void PrintMap();
void Attack();
int map[size][size] = {0};
int ship5_1 [5][2];
int ship5_2 [5][2];
int ship4_1 [4][2];
int ship4_2 [4][2];
int ship3_1 [3][2];
int ship3_2 [3][2];
int ship2_1 [2][2];
int ship2_2 [2][2];
int templateShip [5][2];
int main() {
//    GenerateMap();
    PrintMap();
    Attack();
    return 0;
}

bool GenerateShip(int shipSize){
    srand(time(0));
    int tempMap[size][size];
    Head:
    int sum = 0;
    for (auto & i : tempMap)
        for (int j : i)
            sum += j;
    if(sum == size * size) return false;
    int head[2];
    head[0] = rand() % 10;
    head[1] = rand() % 10;
    tempMap[head[0]][head[1]] = 1;
    if(ValidLocation(head)) {
        templateShip[0][0] = head[0];
        templateShip[0][1] = head[1];
    }
    else goto Head;
    int directionArray[4] = {1,1,1,1};
    Body:
    if(max_element(directionArray,directionArray + sizeof(directionArray)) == 0) goto Head;
    srand(time(0));
    int direction = rand() % 4;
    if(directionArray[direction] == 0) goto Body;
    directionArray[direction] = 0;
    switch (direction) {
        case 0:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip[0][0] - i, templateShip[0][1]};
                if(newLocation[0] >= 0 && ValidLocation(newLocation)) {
                    templateShip[i][0] = newLocation[0];
                    templateShip[i][1] = newLocation[1];
                }
                else goto Body;
            }
        break;
        case 1:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip[0][0] + i, templateShip[0][1]};
                if(newLocation[0] < size && ValidLocation(newLocation)) {
                    templateShip[i][0] = newLocation[0];
                    templateShip[i][1] = newLocation[1];
                }
                else goto Body;
            }
        break;
        case 2:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip[0][0], templateShip[0][1] - i};
                if(newLocation[1] >= 0  && ValidLocation(newLocation)) {
                    templateShip[i][0] = newLocation[0];
                    templateShip[i][1] = newLocation[1];
                }
                else goto Body;
            }
        break;
        case 3:
            for (int i = 1; i < shipSize; ++i) {
                int newLocation[2] = {templateShip[0][0], templateShip[0][1] + i};
                if(newLocation[1] < size  && ValidLocation(newLocation)) {
                    templateShip[i][0] = newLocation[0];
                    templateShip[i][1] = newLocation[1];
                }
                else goto Body;
            }
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
    if(GenerateShip(5))
        for (int i = 0; i < 5; ++i) {
            ship5_1[i][0] = templateShip[i][0];
            ship5_1[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(5))
        for (int i = 0; i < 5; ++i) {
            ship5_2[i][0] = templateShip[i][0];
            ship5_2[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(4))
        for (int i = 0; i < 4; ++i) {
            ship4_1[i][0] = templateShip[i][0];
            ship4_1[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(4))
        for (int i = 0; i < 4; ++i) {
            ship4_2[i][0] = templateShip[i][0];
            ship4_2[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(3))
        for (int i = 0; i < 3; ++i) {
            ship3_1[i][0] = templateShip[i][0];
            ship3_1[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(3))
        for (int i = 0; i < 3; ++i) {
            ship3_2[i][0] = templateShip[i][0];
            ship3_2[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(2))
        for (int i = 0; i < 2; ++i) {
            ship2_1[i][0] = templateShip[i][0];
            ship2_1[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
        }
    if(GenerateShip(2))
        for (int i = 0; i < 2; ++i) {
            ship2_2[i][0] = templateShip[i][0];
            ship2_2[i][1] = templateShip[i][1];
            map[templateShip[i][0]][templateShip[i][1]] = 1;
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

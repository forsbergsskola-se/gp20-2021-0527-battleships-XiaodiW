#include <iostream>
using namespace std;

int main() {
    const int size = 20;
    int frequency[size] = {0};
    int max = 1000000;
    for (int i = 0; i < max; ++i) {
        int number = rand() % size;
        frequency[number] ++;
    }
    float percent[size] = {0.0f};
    float offset[size] = {0.0f};
    float expectFrequency = 1.0f / 20 * 100;
    float offsetSum = 0.0f;
    for (int i = 0; i < size; ++i) {
        percent[i] = static_cast<float>(frequency[i]) / max * 100;
        offset[i] = abs(percent[i] - expectFrequency);
        offsetSum += offset[i];
        cout << "Number " << i << "  " << frequency[i] << " times" << " (" << percent[i] << "%)" << endl;
    }
    int maxIndex = distance(offset,max_element(offset,offset + size));
    cout << "Maximum Offset: Number " << maxIndex << " (" << offset[maxIndex] << "%)" << endl;
    int minIndex = distance(offset,min_element(offset,offset + size));
    cout << "Minimum Offset: Number " << minIndex << " (" << offset[minIndex] << "%)" << endl;
    cout << "Average Offset "<< offsetSum / size << "%" << endl;

    return 0;
}

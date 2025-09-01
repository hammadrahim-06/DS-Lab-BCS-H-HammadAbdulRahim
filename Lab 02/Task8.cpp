#include <iostream>
using namespace std;

int main() {
    int days, times;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Enter number of readings per day: ";
    cin >> times;

    float** temperature = new float*[days];
    for (int i = 0; i < days; i++) {
        temperature[i] = new float[times];
    }

    cout << "\nEnter temperature readings" << endl;
    for (int d = 0; d < days; d++) {
        cout << "Day " << d + 1 << ":" << endl;
        for (int t = 0; t < times; t++) {
            cout << "  Reading " << t + 1 << ": ";
            cin >> temperature[d][t];
        }
    }

    float* dailyAverage = new float[days];
    for (int d = 0; d < days; d++) {
        float sum = 0;
        for (int t = 0; t < times; t++) {
            sum += temperature[d][t];
        }
        dailyAverage[d] = sum / times;
    }

    int hottest = 0, coldest = 0;
    for (int d = 1; d < days; d++) {
        if (dailyAverage[d] > dailyAverage[hottest]) hottest = d;
        if (dailyAverage[d] < dailyAverage[coldest]) coldest = d;
    }

    cout << "\nDaily Average Temperatures" << endl;
    for (int d = 0; d < days; d++) {
        cout << "Day " << d + 1 << ": " << dailyAverage[d] << endl;
    }

    cout << "\nHottest Day: Day " << hottest + 1 << " (Average = " << dailyAverage[hottest] << ")" << endl;
    cout << "Coldest Day: Day " << coldest + 1 << " (Average = " << dailyAverage[coldest] << ")" << endl;

    for (int i = 0; i < days; i++) {
        delete[] temperature[i];
    }
    delete[] temperature;
    delete[] dailyAverage;

    return 0;
}
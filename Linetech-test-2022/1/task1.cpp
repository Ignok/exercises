#include <iostream>
#include <fstream>
#include <future>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


double average();
double median();

int main() {
    double average_val;
    double median_val;

    std::future<double> average_future = std::async(std::launch::async, average);
    std::future<double> median_future = std::async(std::launch::async, median);

    average_val = average_future.get();
    median_val = median_future.get();

    if (average_val > median_val)
        cout << "Average value is bigger: " << average_val << endl;
    else if (median_val > average_val)
        cout << "Median is bigger: " << median_val << endl;
    else 
        cout << "Average value and median are equal: " << average_val << endl;

    return 0;
}

double average() {
    double average = 0.0;
    ifstream File("data.txt");
    if (File.is_open()) {
        int number, count = 0, sum = 0;
        while (File >> number) {
            count++;
            sum += number;
        }
        if (File.eof()) {
            if (count != 0) {
                average = 1.0 * sum / count;
            }
        }
        else {
            cerr << "File read error" << endl;
        }
    }
    else {
        cerr << "File open error" << endl;
    }
    return average;
}

double median() {
    double median;

    fstream file("data.txt");
    vector<int> numbers;

    ifstream File("data.txt");
    if (File.is_open()) {
        int number, count = 0;
        while (File >> number) {
            count++;
            numbers.push_back(number);
        }
        if (File.eof()) {
            if (count != 0) {
                std::sort(numbers.begin(), numbers.end());
                if (count % 2 == 0) {
                    median = (1.0 * numbers[count/2 - 1] + numbers[count/2]) / 2.0;
                } else {
                    median = 1.0 * numbers[count/2];
                }
            }
        }
        else {
            cerr << "File read error" << endl;
        }
    }
    else {
        cerr << "File open error" << endl;
    }

    

    return median;
}

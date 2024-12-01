#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility> // for pair
#include <algorithm>
#include <numeric>
#include <filesystem>
#include <unordered_map>

using namespace std;
using namespace std::filesystem;

void part1() {
    const string filePath = "input1.txt";
    ifstream file(filePath);

    if (!exists(filePath)) {
        cerr << "File does not exist: " << filePath << endl;
        return;
    }

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    // vector<pair<int, int>> intPairs;
    vector<int> leftList;
    vector<int> rightList;
    int a, b;

    while (file >> a >> b) {
        leftList.emplace_back(a);
        rightList.emplace_back(b);
    }

    file.close();

    sort(leftList.begin(), leftList.end(), [](const int& p1, const int& p2) {
            return p1 < p2;
        });

    sort(rightList.begin(), rightList.end(), [](const int& p1, const int& p2) {
            return p1 < p2;
        });

    // for (const auto& [first, second] : intPairs) {
    //     cout << first << " " << second << endl;
    // }

    vector<int> diff;

    for(int i = 0; i < leftList.size(); i++) {
        diff.emplace_back(abs(leftList[i] - rightList[i]));
    }

    int sum = accumulate(diff.begin(), diff.end(), 0);

    cout << sum;
}

void part2() {
    const string filePath = "input1.txt";
    ifstream file(filePath);

    if (!exists(filePath)) {
        cerr << "File does not exist: " << filePath << endl;
        return;
    }

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    // vector<pair<int, int>> intPairs;
    vector<int> leftList;
    vector<int> rightList;
    int a, b;

    while (file >> a >> b) {
        leftList.emplace_back(a);
        rightList.emplace_back(b);
    }

    file.close();

    unordered_map<int, int> frequency;
    for (const int& num : rightList) {
        frequency[num]++;
    }

    vector<int> similarity;

    for(int i : leftList) {
        similarity.emplace_back(i*frequency[i]);
    }

    const int sum = accumulate(similarity.begin(), similarity.end(), 0);

    cout << sum;
}

int main() {
    // part1();
    part2();

    return 0;
}

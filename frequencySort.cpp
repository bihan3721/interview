#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct MyCmp
{
    unordered_map<int, int> map;
    MyCmp(const unordered_map<int, int>& map_):map(map_) {}

    bool operator()(int i, int j) {
        return map[i] > map[j];
    }
};

void frequencySort(vector<int>& numbers)
{
    unordered_map<int, int> map;
    for (int i=0; i<numbers.size(); ++i)
    {
        map[numbers[i]]++;
    }

    sort(numbers.begin(), numbers.end(), MyCmp(map));
}

int main()
{
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(3);
    numbers.push_back(9);
    numbers.push_back(5);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(9);
    frequencySort(numbers);

    for (int i=0; i<numbers.size(); ++i)
    {
        cout << numbers[i] << ", " << endl;
    }
}

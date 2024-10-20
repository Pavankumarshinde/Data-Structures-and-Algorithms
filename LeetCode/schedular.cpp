#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getMinCores(vector<int>& start, vector<int>& end) {
    vector<pair<int, char>> events;

    // Create events for all start and end times
    for (int i = 0; i < start.size(); ++i) {
        events.emplace_back(start[i], 's'); // 's' for start
        events.emplace_back(end[i], 'e');   // 'e' for end
    }

    // Sort events: first by time, then by type ('e' before 's' if times are the same)
    sort(events.begin(), events.end(), [](pair<int, char>& a, pair<int, char>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    int maxCores = 0;
    int currentCores = 0;

    // Process events
    for (auto& event : events) {
        if (event.second == 's') {
            currentCores++; // A process starts, so we need one more core
            maxCores = max(maxCores, currentCores);
        } else {
            currentCores--; // A process ends, so we can free a core
        }
    }

    return maxCores;
}

int main() {
    vector<int> start = {1, 3, 4};
    vector<int> end = {3, 5, 6};
    
    cout << getMinCores(start, end) << endl; // Output should be 2

    return 0;
}

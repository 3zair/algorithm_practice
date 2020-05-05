#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

int findLucky(vector<int>& arr) {
    sort(arr.rbegin(), arr.rend());
    int lucky = arr[0];
    int count = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == lucky) {
            count++;
        } else {
            if (lucky == count) {
                return lucky;
            } else {
                lucky = arr[i];
                count = 1;
            }
        }
    }
    if (lucky == count) {
        return lucky;
    }

    return -1;
}

//
int numTeams(vector<int>& rating) {
    int count = 0;
    int f = rating[0];
    for (int n = 0; n < rating.size(); ++n) {
        for (int i = n + 1; i < rating.size(); ++i) {
            if (rating[i] > rating[n]) {
                for (int j = i + 1; j < rating.size(); ++j) {
                    if (rating[j] > rating[i]) {
                        count++;
                    }
                }
            } else if (rating[i] < rating[n]) {
                for (int j = i + 1; j < rating.size(); ++j) {
                    if (rating[j] < rating[i]) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

class UndergroundSystem {
   private:
    map<string, vector<int>> stations;
    map<int, string> StartStationsPass;
    map<int, int> passengers;

   public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        passengers[id] = t;
        StartStationsPass[id] = stationName;
    }

    void checkOut(int id, string stationName, int t) {
        stations[StartStationsPass[id] + stationName].emplace_back(
            t - passengers[id]);
        passengers.erase(id);
        StartStationsPass.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        if (stations.find(startStation + endStation) != stations.end()) {
            vector<int> ts = stations[startStation + endStation];
            int sum = 0;
            for (int i = 0; i < ts.size(); ++i) {
                sum += ts[i];
            }
            return double(sum) / double(ts.size());
        }

        return 0;
    }
};

int main() {}
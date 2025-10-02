#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits.h>

bool sortByFinish(const std::pair<int,int> &p1, const std::pair<int,int> &p2) {
    return p1.second < p2.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // First input
    int n;
    std::cin >> n;

    std::vector<std::pair<int,int>> vec;
    
    int a, b;
    // Interval inputs
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        vec.push_back(std::make_pair(a,b));
    }

    // Greedy idea: Presort the pairs by finishing time
    std::sort(std::begin(vec), std::end(vec), sortByFinish);

    int res = 0;
    
    // Process intervals, ignoring those which are overlapping
    std::pair<int,int> currOverlap = std::make_pair(INT_MIN, INT_MIN);
    for (auto i : vec) {
        if ((i.first <= currOverlap.first && i.second >= currOverlap.first) || (i.second >= currOverlap.second && i.first <= currOverlap.second)) {
            continue;
        } 
        res++;
        currOverlap = i;
    }

    std::cout << res;
    


    return 0;
}

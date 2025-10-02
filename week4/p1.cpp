#include <algorithm>
#include <iostream>
#include <vector>

struct flight_data
{
    int src;
    int dst;
    int cost;

    flight_data(int src, int dst, int cost)
        : src(src)
        , dst(dst)
        , cost(cost)
    {
    }
};

int main()
{
    int n;
    std::cin >> n;
    int table[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> table[i][j];
        }
    }

    // Each entry contains (src,dst,cost) for all entries with non-negative cost
    std::vector<flight_data> res;
    int                      num_flights = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int cost = table[i][j];
            if(table[i][j] > 0)
            {
                res.emplace_back(i + 1, j + 1, cost);
                num_flights++;
            }
        }
    }
    std::cout << num_flights << "\n";
    std::sort(res.begin(), res.end(), [](const flight_data& a, const flight_data& b) {
        if(a.src == b.src)
            return a.dst < b.dst;
        return a.src < b.src;
    });
    for(const auto& s : res)
    {
        std::cout << s.src << " " << s.dst << " " << s.cost << "\n";
    }
    return 0;
}

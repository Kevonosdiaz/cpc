#include <iostream>
#include <unordered_set>
#include <vector>

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

    std::unordered_set<int> usi;
    for(int i = 0; i < n; i++)
    {
        int              local_count = 0;
        std::vector<int> local_neighbours{};
        for(int j = 0; j < n; j++)
        {
            if(table[i][j])
            {
                local_count++;
                local_neighbours.push_back(j);
            }
        }
        // How do we check which neighbours are neighbours of each other?
        for(auto i : local_neighbours)
        {
            for(auto j : local_neighbours)
            {
                if(i == j)
                    continue;
                if(table[i][j])
                {
                    usi.emplace(i);
                }
            }
        }
    }

    for(auto i : usi)
    {
        std::cout << i << " ";
    }
}

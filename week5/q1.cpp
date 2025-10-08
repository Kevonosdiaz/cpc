#include <iostream>
#include <queue>
#include <stack>
#include <utility>

int main()
{
    int n;
    while(std::cin >> n)
    {
        // 1 indicates push
        // 2 indicates pop
        // std::vector<std::pair<int,int>> ops(n);

        std::stack<int>          st;
        std::queue<int>          q;
        std::priority_queue<int> pq; // Note: max heap

        bool is_st = 1;
        bool is_q  = 1;
        bool is_pq = 1;

        std::vector<std::pair<int, int>> values(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> values[i].first >> values[i].second;
        }
        // Sequentially just try them all until it fails and parse results?
        // If an invalid operation is given, should be impossible as well...
        int num_push = 0;
        int num_pop  = 0;
        for(int i = 0; i < n; i++)
        {
            int op = values[i].first;
            if(op == 1)
                num_push++;
            if(op == 2)
                num_pop++;
            if(num_pop > num_push)
            {
                // Impossible case
                is_st = 0;
                is_q  = 0;
                is_pq = 0;
            }
            int val = values[i].second;
            // Stack stuff
            if(is_st)
            {
                if(op == 1)
                    st.push(val);
                else
                {
                    int t = st.top();
                    st.pop();
                    is_st = t == val;
                }
            }
            if(is_q)
            {
                if(op == 1)
                    q.push(val);
                else
                {
                    int t = q.front();
                    q.pop();
                    is_q = t == val;
                }
            }
            if(is_pq)
            {
                if(op == 1)
                    pq.push(val);
                else
                {
                    int t = pq.top();
                    pq.pop();
                    is_pq = t == val;
                }
            }
        }

        // Print results
        if(!is_st && !is_q && !is_pq)
            std::cout << "impossible\n";
        else if(is_st && !is_q && !is_pq)
            std::cout << "stack\n";
        else if(!is_st && is_q && !is_pq)
            std::cout << "queue\n";
        else if(!is_st && !is_q && is_pq)
            std::cout << "priority queue\n";
        else
            std::cout << "not sure\n";
    }
}

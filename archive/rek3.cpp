#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

typedef struct
{
    int remaining_fuel;
    int sold_fruits;
    int current_town_id;
} node;

typedef struct
{
    int stop_at;
    int total_profit;
    int fruits_sold;
} profit_info;

int main()
{
    unordered_map<int, int> fruits_at_town;
    int towns, fuel, fruit_profit, fuel_profit;
    int fuel_costs[towns + 2][towns + 2] = {0};
    unordered_map<int, vector<int>> available_routes;

    cin >> towns >> fuel >> fruit_profit >> fuel_profit;

    for (int i = 0; i < towns; i++)
    {
        int town, fruits;
        cin >> town >> fruits;
        fruits_at_town[town] = fruits;
    }

    while (!cin.eof())
    {
        int from, to, fuel_cost;
        cin >> from >> to >> fuel_cost;
        fuel_costs[from][to] = fuel_cost;
        available_routes[from].push_back(to);
    }

    queue<node> traversal;
    traversal.push({fuel, fruits_at_town[1], 1});

    profit_info most_profitable = {0, 0, 0};

    while (!traversal.empty())
    {
        node current = traversal.front();
        traversal.pop();
        int c_profit = current.remaining_fuel * fuel_profit + current.sold_fruits * fruit_profit;
        if (most_profitable.total_profit < c_profit)
        {
            most_profitable = {current.current_town_id, c_profit, current.sold_fruits};
        }
        for (int next_town : available_routes[current.current_town_id])
        {
            int remaining_fuel = current.remaining_fuel - fuel_costs[current.current_town_id][next_town];
            if (remaining_fuel >= 0)
            {
                traversal.push({remaining_fuel,
                                current.sold_fruits + fruits_at_town[next_town],
                                next_town});
            }
        }
    }

    cout << most_profitable.stop_at << " " << most_profitable.total_profit << " " << most_profitable.fruits_sold << endl;

    return 0;
}
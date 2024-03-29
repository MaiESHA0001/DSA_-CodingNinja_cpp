Problem statement
Ninja is planning to make dessert. For which he is going to buy ingredients. There are ‘N’ base flavors and ‘M’ toppings. Ninja has a target that he will be needing an amount of ‘K’ for making the dessert.

For making dessert, there are some basic rules

1. There should be exactly one base flavor.
2. Toppings can be one or more or none.
3. There are at most two toppings of each type.
Ninja wants to make a dessert with a total cost as close to the target price as possible.

You will be given an array/list flavor of size N representing the cost of each base flavor and another array/list toppings of size 'M' representing the cost of each topping and the target price.

Your task is to help Ninja to find the closest possible cost of the dessert to the target price 'K'. If there are multiple answers, return the lower one.

Example

Let N = 2 , M = 2 , K = 10, FLAVOR = [1,7] , TOPPING = [3, 4] , K = 10

Here we can make a dessert with the base flavor of price 7 and adding 1 topping of price 3. Which will cost 7 + 3 = 10, which is exactly equal to k, so the closest possible price would be 10.
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= T <= 5
1 <= N, M <= 10
1 <= FLAVOUR[i] , TOPPINGS[i] <= 10 ^ 4
1 <= K <= 10 ^ 4 

Time limit: 1 sec.
Sample Input 1
2
2
1 7
3
1 2 3
10
1
10
3
5 6 11
9
Sample Output 1
10
10
Explanation
Test case 1

In this case, Ninja has 2 base flavours of cost 1 and 7,  and 3 toppings of price 1 and 2. Here target price is 10. So if Ninja takes a base of cost 7 and 1 topping of cost 3, then Ninja can make a dessert exactly of cost 10 ( 7 + 3), i.e., target price.

Test case 2

In this case, Ninja has only one base flavour of cost 10 and 3 toppings of 5, 6, 11. To make the dessert, Ninja must need a base, so 10 is the minimum cost that he must spend. Now, if he will add toppings price will rise further. So the closest possible price is 10.
Sample Input 2:
2
4
1 8 3 4
3
2 3 4
20
1
2
1
2
7
Sample Output 2:
20
6

















  #include <bits/stdc++.h>
using namespace std;

void generateCosts(vector<int> &toppingCosts, int idx, int current, set<int> &possibleCosts) {
    if (idx == toppingCosts.size()) {
        possibleCosts.insert(current);
        return;
    }
    
    generateCosts(toppingCosts, idx + 1, current, possibleCosts); // Exclude the current topping
    generateCosts(toppingCosts, idx + 1, current + toppingCosts[idx], possibleCosts); // Include one of the current topping
    generateCosts(toppingCosts, idx + 1, current + 2 * toppingCosts[idx], possibleCosts); // Include two of the current topping
}

int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
    set<int> possibleCosts;
    
    // Generate all possible topping costs
    generateCosts(toppingCosts, 0, 0, possibleCosts);
    
    int closest = INT_MAX;
    
    // Check all combinations of base flavors and topping costs
    for (int base : baseCosts) {
        for (int topping : possibleCosts) {
            int currentCost = base + topping;
            
            // Update closest cost if current combination is closer to the target
            if (abs(target - currentCost) < abs(target - closest) || (abs(target - currentCost) == abs(target - closest) && currentCost < closest)) {
                closest = currentCost;
            }
        }
    }
    
    return closest;
}



























#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#include "solution.h"

class Runner
{
    int t;
    vector<int> n, m, target;
    vector<vector<int>> base, toppings;

public:
    void takeInput()
    {
        cin >> t;

        for (int i = 0; i < t; i++)
        {
            int N;
            cin >> N;
            n.push_back(N);

            vector<int> v;
            for (int j = 0; j < N; j++)
            {
                int B;
                cin >> B;
                v.push_back(B);
            }
            base.push_back(v);

            int M;
            cin >> M;
            m.push_back(M);

            vector<int> u;
            for (int k = 0; k < M; k++)
            {
                int top;
                cin >> top;
                u.push_back(top);
            }

            toppings.push_back(u);

            int tar;
            cin >> tar;

            target.push_back(tar);
        }
    }

    void execute()
    {
        vector<vector<int>> cpyB = base;
        vector<vector<int>> cpyT = toppings;

        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
//freopen("TestCases/large/in/input11.txt", "r", stdin);
//freopen("TestCases/large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}



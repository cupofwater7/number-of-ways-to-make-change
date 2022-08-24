#include <vector>
#include <iostream>
using namespace std;
int numberOfWaysToMakeChange(int n, vector<int> denoms);

int main()
{
    cout << numberOfWaysToMakeChange(6, { 1, 5 }) << " ";
    return 0;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    // Write your code here.
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int denom : denoms)
    {
        for (int amount = 1; amount < n + 1; amount++)
        {
            if (denom <= amount)
                ways[amount] += ways[amount - denom];
        }
    }
    return ways[n];

}

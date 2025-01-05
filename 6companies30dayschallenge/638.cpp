class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }

private:
    int dfs(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs) {
        int minCost = directPurchase(price, needs);

        for (const auto& offer : special) {
            vector<int> updatedNeeds = needs;
            bool validOffer = true;

            for (int i = 0; i < needs.size(); ++i) {
                if (updatedNeeds[i] < offer[i]) {
                    validOffer = false;
                    break;
                }
                updatedNeeds[i] -= offer[i];
            }

            if (validOffer) {
                minCost = min(minCost, offer.back() + dfs(price, special, updatedNeeds));
            }
        }

        return minCost;
    }

    int directPurchase(const vector<int>& price, const vector<int>& needs) {
        int total = 0;
        for (int i = 0; i < price.size(); ++i) {
            total += price[i] * needs[i];
        }
        return total;
    }
};

#include <iostream>
#include <vector>

using namespace std;

long long countIncremovableSubarrays(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    long long ans = 0;

    // Find the longest strictly increasing prefix
    while (i < n - 1 && nums[i] < nums[i + 1]) {
        i++;
    }

    // If the entire array is strictly increasing
    if (i == n - 1) {
        return static_cast<long long>(n) * (n + 1) / 2;
    }

    // Count subarrays that can be removed to maintain the increasing prefix
    ans += i + 2;

    // Two-pointer approach to count valid subarrays
    for (int j = n - 1; j > 0; j--) {
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
        }
        ans += i + 2;
        if (nums[j - 1] >= nums[j]) {
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 5, 4, 6};
    cout << "Number of incremovable subarrays: " << countIncremovableSubarrays(nums) << endl;
    return 0;
}

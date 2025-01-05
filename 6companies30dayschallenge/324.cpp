class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int median = *midptr;

        // Mapping function to virtual index
        auto index = [n](int i) { return (1 + 2 * i) % (n | 1); };

        int left = 0, i = 0, right = n - 1;

        // Three-way partitioning
        while (i <= right) {
            if (nums[index(i)] > median) {
                swap(nums[index(left)], nums[index(i)]);
                ++left;
                ++i;
            } else if (nums[index(i)] < median) {
                swap(nums[index(i)], nums[index(right)]);
                --right;
            } else {
                ++i;
            }
        }
    }
};

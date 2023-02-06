
#include <vector>
#include <numeric>
#include <variant>
using namespace std;

class Solution {
    
public:
    vector<int> separateDigits(const vector<int>& input) const {
        auto digits = [&](int partialSum, int current) {partialSum += calculateDigitsForInteger(current); return partialSum;};
        int totalInputDigits = accumulate(input.begin(), input.end(), 0, digits);

        vector<int>separatedDigits(totalInputDigits);
        size_t index = separatedDigits.size() - 1;

        for (size_t i = input.size() - 1; i != variant_npos; --i) {
            int current = input[i];
            // 1 <= nums[i] <= pow(10,5), therefore handling case 'current = 0' is not needed.
            while (current > 0) {
                separatedDigits[index--] = current % 10;
                current /= 10;
            }
        }
        return separatedDigits;
    }
    
private:
    int calculateDigitsForInteger(int num) const {
        int totalDigits = 0;
        while (num > 0) {
            ++totalDigits;
            num /= 10;
        }
        // 1 <= nums[i] <= pow(10,5), therefore handling case 'current = 0' is not needed.
        return totalDigits;
    }
};

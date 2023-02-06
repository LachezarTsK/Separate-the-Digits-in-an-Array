
import java.util.Arrays;

public class Solution {

    public int[] separateDigits(int[] input) {
        int totalInputDigits = Arrays.stream(input).reduce(0, (partialSum, current) -> partialSum + calculateDigitsForInteger(current));
        int[] separatedDigits = new int[totalInputDigits];
        int index = separatedDigits.length - 1;

        for (int i = input.length - 1; i >= 0; --i) {
            int current = input[i];
            // 1 <= nums[i] <= Math.pow(10,5), therefore handling case 'current = 0' is not needed.
            while (current > 0) {
                separatedDigits[index--] = current % 10;
                current /= 10;
            }
        }
        return separatedDigits;
    }

    private int calculateDigitsForInteger(int num) {
        int totalDigits = 0;
        while (num > 0) {
            ++totalDigits;
            num /= 10;
        }
        // 1 <= nums[i] <= Math.pow(10,5), therefore handling case 'current = 0' is not needed.
        return totalDigits;
    }
}

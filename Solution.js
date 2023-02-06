
/**
 * @param {number[]} input
 * @return {number[]}
 */
var separateDigits = function (input) {
    const totalInputDigits = input.reduce((partialSum, current) => partialSum + calculateDigitsForInteger(current), 0);
    const separatedDigits = new Array(totalInputDigits);
    let index = separatedDigits.length - 1;

    for (let i = input.length - 1; i >= 0; --i) {
        let current = input[i];
        // 1 <= nums[i] <= Math.pow(10,5), therefore handling case 'current = 0' is not needed.
        while (current > 0) {
            separatedDigits[index--] = current % 10;
            current = Math.floor(current / 10);
        }
    }
    return separatedDigits;
};

/**
 * @param {number} num
 * @return {number}
 */
function calculateDigitsForInteger(num) {
    let totalDigits = 0;
    while (num > 0) {
        ++totalDigits;
        num = Math.floor(num / 10);
    }
    // 1 <= nums[i] <= Math.pow(10,5), therefore handling case 'current = 0' is not needed.
    return totalDigits;
}

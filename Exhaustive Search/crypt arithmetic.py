def is_valid(arr, S, char_to_digit):
    nums = []
    for word in arr:
        num = 0
        for char in word:
            num = num * 10 + char_to_digit[char]
        nums.append(num)
    
    target = 0
    for char in S:
        target = target * 10 + char_to_digit[char]

    return nums[0] + nums[1] == target

def solve_crypt_arithmetic(arr, S):
    chars = set(''.join(arr) + S)
    if len(chars) > 10:
        return "No solution possible" 
    
    digits = list(range(10))
    for perm in get_permutations(digits, len(chars)):
        char_to_digit = {char: digit for char, digit in zip(chars, perm)}
        if char_to_digit[arr[0][0]] == 0 or char_to_digit[arr[1][0]] == 0 or char_to_digit[S[0]] == 0:
            continue  
        
        if is_valid(arr, S, char_to_digit):
            print("Yes")
            print("Encoding for CROSS:", ''.join(str(char_to_digit[char]) for char in arr[0]))
            print("Encoding for ROADS:", ''.join(str(char_to_digit[char]) for char in arr[1]))
            print("Encoding for DANGER:", ''.join(str(char_to_digit[char]) for char in S))
            return
        
    print("No solution possible")

def get_permutations(nums, k):
    result = []
    if k == 0:
        return [[]]
    for i in range(len(nums)):
        n = nums[i]
        remaining_nums = nums[:i] + nums[i+1:]
        for p in get_permutations(remaining_nums, k-1):
            result.append([n] + p)
    return result

# Example usage
arr = ["CROSS", "ROADS"]
S = "DANGER"
solve_crypt_arithmetic(arr, S)

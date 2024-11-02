#!/usr/bin/env python3

import sys
from typing import Callable
assert len(sys.argv) >= 2

testname = sys.argv[1]

def is_well_formatted_array(line : str) -> bool:
    if line[-1] != '\n':
        return False
    line = line[:-1]
    if not all(c.isdigit() or c == '-' or c == ' ' for c in line):
        return False
    if line.strip() != line:
        return False
    try:
        arr = [int(x, base=10) for x in line.split()]
        if line.count(' ') != len(arr) - 1:
            return False
    except ValueError:
        return False
    return True

def is_sorted(arr : list, key : Callable[[int], int] ) -> bool:
    for i in range(1, len(arr)):
        if key(arr[i]) < key(arr[i - 1]):
            return False
    return True

        
with open(f"test-data/{testname}.in", "r") as test, open(f"test-data/{testname}.out", "r") as actual, open(f"test-data/{testname}.sol", "r") as expected:
    test_data = test.readlines()
    actual_data = actual.readlines()
    if (len(expected.readlines()) != len(actual_data)):
        sys.exit(1)
    current_line = 0
    current_ans = 0
    while current_line < len(test_data):
        if test_data[current_line].strip() == "3":
            
            current_line += 2
            arr = [int(x) for x in test_data[current_line].split()]
            current_line += 1
            summ = sum(arr)
            arr.sort(key = abs)
            
            actual_sum = int(actual_data[current_ans])
            current_ans += 1
            actual_sorted = actual_data[current_ans]
            current_ans += 1
            if summ != actual_sum:
                print(f"Wrong sum: {summ} expected, {actual_sum} given")
                sys.exit(1)
            if not is_well_formatted_array(actual_sorted):
                print(f"`{actual_sorted}` is not well formatted array")
                sys.exit(1)
            if not is_sorted([int(x) for x in actual_sorted.split()], abs):
                print("array is not sorted")
                sys.exit(1)
        else:
            current_line += 1 if test_data[current_line].strip() == "1" else 2
            current_ans += 1
            
sys.exit(0)

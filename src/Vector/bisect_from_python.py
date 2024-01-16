"""
copied from https://github.com/python/cpython/blob/main/Lib/bisect.py

I add some comments to analyse the correctness of bisect_left() and bisect_right()

The analysis is a little different from interpolation search.
You can refer to src/Vector/Vector_search_interpolation.h
"""

"""Bisection algorithms."""


def binary_search(a, x):
    """I add this function, 
    if x is in a, just return one index (not necessarily the leftmost or the rightmost)
    if x is not in a, return i such that x can be inserted before a[i]
    
    Prove: the algorithm is correct
    proof: 
    step 1: let's prove it is finite
        when low <= high, we have  low <= mid <= high, so after each loop, 
        the width of [low, high] will decrease strictly
                             
    step 2: let's prove the return value meets the requirements
        two key observations:
        observation 1. if "a[mid] < x" branch has been executed at least once, then we have
            a[low - 1] < x ("low" is changed, the index "low - 1" is not out of bounds)
        observation 2. if "x < a[mid]" branch has been executed at least once, then we have
            x < a[high + 1] ("high" is changed, the index "high + 1" is not out of bounds)
        
        (Caution: the trick for me is rewrite "a[mid] < x" as "a[low - 1] < x",
        rewrite "x < a[mid]" as "x < a[high + 1]")    
          
        when we exit the loop, we have high = low - 1
        
        case 1: "a[mid] < x" branch and "x < a[mid]" branch have both been executed at least once previously:
            a[low - 1] < x < a[high + 1]
            high = low - 1
            so we have
            a[low - 1] < x < a[low]
            so we should return "low" or "high + 1"
            
        case 2: "a[mid] < x" branch has never been executed
            "low" is never changed
            x < a[high + 1]
            high = low - 1
            so we should return "low" or "high + 1"
            
        case 3: "x < a[mid]" branch has never been executed
            "high" is never changed
            a[low - 1] < x
            high = low - 1
            so we should return "low" or "high + 1"
            
    """
    low, high = 0, len(a) - 1
    assert low <= high
    while low <= high:
        mid = (low + high) // 2
        if a[mid] < x:
            low = mid + 1
        elif x < a[mid]:
            high = mid - 1
        else:
            return mid
    assert high == low - 1
    return low


def insort_right(a, x, lo=0, hi=None, *, key=None):
    """Insert item x in list a, and keep it sorted assuming a is sorted.

    If x is already in a, insert it to the right of the rightmost x.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.

    A custom key function can be supplied to customize the sort order.
    """
    if key is None:
        lo = bisect_right(a, x, lo, hi)
    else:
        lo = bisect_right(a, key(x), lo, hi, key=key)
    a.insert(lo, x)


def bisect_right(a, x, lo=0, hi=None, *, key=None):
    """Return the index where to insert item x in list a, assuming a is sorted.

    The return value i is such that all e in a[:i] have e <= x, and all e in
    a[i:] have e > x.  So if x already appears in the list, a.insert(i, x) will
    insert just after the rightmost x already there.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.

    A custom key function can be supplied to customize the sort order.
    
    
    
    ==================  start: method 1 (just ignore this method)================
    
    Prove: the algorithm is correct
    proof: (method 1, very tedious, just ignore this method) 
    step 1: let's prove the algorithm is finite
        when hi - lo >= 1, we have  low <= mid < hi, so after each loop, 
        the width of [lo, hi) will decrease strictly
                             
    step 2: let's prove the return value meets the requirements
        two key observations:
        observation 1. if "x < a[mid]" branch has been executed at least once, then we have
            x < a[hi, len(a)) (this slice is not empty, "hi" is changed)
        observation 2. if "a[mid] <= x" branch has been executed at least once, then we have
            a[0, lo) <= x (this slice is not empty, "lo" is changed)
                
        case 1: hi = lo + 1
            mid = lo
            if "x < a[mid]" branch is executed:
                hi <--- mid,
                so now lo = mid = hi, x < a[lo]
                according to observation 2:
                    if "a[mid] <= x" branch has been executed at least once previously:
                        a[0, lo) <= x < a[lo]
                        so we should return "lo" or "hi"
                    else 
                        lo is never changed
                        hi = initial lo
                        x < a[lo]
                        so we should return "lo" or "hi"
            else
                a[mid] <= x  
                lo <--- mid + 1
                so now lo = hi, mid = lo - 1, a[lo - 1] <= x
                according to observation 1:
                    if "x < a[mid]" branch has been executed at least once previously:
                        x < a[hi, len(a))
                        so we have a[lo - 1] <= x < a[lo, len(a))
                        so we should return "lo" or "hi"
                    else
                        hi is never changed
                        lo = initial hi
                        a[lo - 1] <= x
                        so we should return "lo" or "hi"
                        
        case 2: hi = lo + 2
            mid = lo + 1
            if "x < a[mid]" branch is executed:
                hi <--- mid
                goto case 1
            else:
                a[mid] <= x
                lo <--- mid + 1
                so now, we have lo = hi, mid = lo - 1, a[lo - 1] <= x
                according to observation 1:
                    if "x < a[mid]" branch has been executed at least once previously:
                        x < a[hi, len(a))
                        so we have a[lo - 1] <= x < a[lo, len(a))
                        so we should return "lo" or "hi"
                    else:
                        hi is never changed
                        lo = initial hi
                        a[lo - 1] <= x
                        so we should return "lo" or "hi"
                        
        case 3: hi = lo + 3
            mid = (lo + lo + 3)//2 =   lo + 1
            after this loop, we can enter the loop again 
            
    conclusion: you can return "lo" or "hi"  
    
    ==================  end: method 1 ================
    
    ==================  start: method 2 ================
    Prove: the algorithm is correct
    proof: (method 2, more concise, this is what I want)  
    step 1: finite
        when lo < hi, we have lo <= mid < hi, 
        after one loop, the width of [lo, hi) decreases strictly
    
    step 2: 
        two key observation:
        observation 1: if "x < a[mid]" branch has been executed at least once, we have
            x < a[hi] (hi is changed, the index "hi" is not out of bounds)                              
        observation 2: if "a[mid] <= x" branch has been executed at least once, we have
            a[lo - 1] <= x (lo is changed, the index "lo" is not out of bounds)
        (Caution: the trick is to replace "mid" with expression of "lo" or "hi")
        
        case 1: hi = lo + 3
            mid = (lo + lo + 3) // 2 = lo + 1
            we can enter the loop again
        case 2: hi = lo + 2
            mid = (lo + lo + 2) // 2 = lo + 1
            when we exit the loop, we have lo = hi
        case 3: hi = lo + 1
            mid = (lo + lo + 1) // 2 = lo
            when we exit the loop, we have lo = hi
        
        so, from case 1-3, we know that when we exit the loop, we have lo = hi
        
        when we exit the loop:
            case 1b: if "x < a[mid]" branch and "a[mid] <= x" branch have both been executed at least once
                a[lo - 1] <= x < a[hi]
                lo = hi
                so we have 
                a[lo - 1] <= x < a[lo]
                so we should return "lo" or "hi"
            
            case 2b: if "x < a[mid]" branch has never been executed
                hi is never changed
                a[lo - 1] <= x
                hi = lo
                so we should return "lo" or "hi"
                
            case 3b: if "a[mid] <= x" branch has never been executed
                lo is never changed
                x < a[hi]
                hi = lo
                so we should return "lo" or "hi"
    
    conclusion: we should return "lo" or "hi"     
    
    ==================  end: method 2 ================
    
    """

    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    # Note, the comparison uses "<" to match the
    # __lt__() logic in list.sort() and in heapq.
    assert lo < hi
    if key is None:
        while lo < hi:
            mid = (lo + hi) // 2
            if x < a[mid]:
                hi = mid
            else:
                lo = mid + 1
    else:
        while lo < hi:
            mid = (lo + hi) // 2
            if x < key(a[mid]):
                hi = mid
            else:
                lo = mid + 1
    
    assert lo == hi
    
    return lo
  

def insort_left(a, x, lo=0, hi=None, *, key=None):
    """Insert item x in list a, and keep it sorted assuming a is sorted.

    If x is already in a, insert it to the left of the leftmost x.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.

    A custom key function can be supplied to customize the sort order.
    """

    if key is None:
        lo = bisect_left(a, x, lo, hi)
    else:
        lo = bisect_left(a, key(x), lo, hi, key=key)
    a.insert(lo, x)


def bisect_left(a, x, lo=0, hi=None, *, key=None):
    """Return the index where to insert item x in list a, assuming a is sorted.

    The return value i is such that all e in a[:i] have e < x, and all e in
    a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
    insert just before the leftmost x already there.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.

    A custom key function can be supplied to customize the sort order.
    
    
    ==================  start: method 1 (just ignore this method) ================
    
    Prove: this algorithm is correct
    proof: (it is similar to the method 1 of bisect_right(),
    very tedious, just ignore this method)
    step 1: let's prove it is finite
        when hi - lo >= 1, we know lo <= mid < hi
        so after one loop, the width of [lo, hi) decreases strictly
        
    step 2: let's prove the return value meets the requirements
        two key observations:
        observation 1. if "a[mid] < x" branch has been executed at least once, then we have
            a[0, lo) < x (this slice is not empty, "lo" is changed)
        observation 2. if "x <= a[mid]" branch has been executed at least once, then we have
            x <= a[hi, len(a)) (this slice is not empty, "hi" is changed)
        
        case 1: hi = lo + 1
            mid = lo
            if "a[mid] < x" branch is executed:
                lo <--- mid + 1
                now , we have lo = hi, mid = lo - 1, a[lo - 1] < x
                according to observation 2:
                    if "x <= a[mid]" branch has been executed at least once previously:
                        x <= a[hi, len(a))
                        so we have
                        a[lo - 1] < x <= a[lo, len(a))
                        so we should return lo or hi 
                    else:
                        hi is never changed
                        lo = initial hi
                        a[lo - 1] < x
                        so we should return lo or hi 
            else:
                x <= a[mid]
                hi <--- mid
                now , we have hi = lo = mid, x <= a[lo]
                according to observation 1:
                    if "a[mid] < x" branch has been executed at least once previously:
                        a[0, lo) < x <= a[lo]
                        so we should return lo or hi
                    else:
                        lo is never changed
                        x <= a[lo]
                        so we should return lo or hi
                        
        case 2: hi = lo + 2
            mid = lo + 1
            if "a[mid] < x" branch is executed:
                lo <--- mid + 1
                now, we have lo = hi, mid = lo - 1, a[lo - 1] < x
                according to observation 2:
                    if "x <= a[mid]" branch has been executed at least once:
                        x <= a[hi, len(a))
                        so we have
                        a[lo - 1] < x <= a[lo, len(a))
                        so we should return lo or hi
                    else:
                        hi is never changed
                        lo = initial hi
                        a[lo - 1] < x
                        so we should return lo or hi
            else:
                x <= a[mid]
                hi <--- mid
                goto case 1
        
        case 3: hi = lo + 3
            mid = (lo + lo + 3)//2 =   lo + 1
            after this loop, we can enter the loop again 
                            
    conclusion: we should return lo or hi    
    
    ==================  end: method 1 ================
    
    
    ==================  start: method 2 ================
    
    Prove: this algorithm is correct
    proof: (it is similar to the method 2 of bisect_right())
    step 1: let's prove it is finite
        when hi - lo >= 1, we know lo <= mid < hi
        so after one loop, the width of [lo, hi) decreases strictly
        
    step 2: let's prove the return value meets the requirements
        two key observations:
        observation 1. if "a[mid] < x" branch has been executed at least once, then we have
            a[lo - 1] < x ("lo" is changed)
        observation 2. if "x <= a[mid]" branch has been executed at least once, then we have
            x <= a[hi] ("hi" is changed)
        
        case 1a: hi = lo + 1
            mid = (lo + lo + 1)//2 = lo 
            when we exit the loop, we have hi = lo
        
        case 2a: hi = lo + 2
            mid = (lo + lo + 2)//2 = lo + 1
            when we exit the loop, we have hi = lo
            
        case 3a: hi = lo + 3
            mid = (lo + lo + 3)//2 = lo + 1
            we can enter the loop again, ignore this case
        
        so, from case 1a - 3a, we know that when we exit the loop, we have hi = lo
        
        when we exit the loop:
            case 1b: if both branches have been executed at least once
                a[lo - 1] < x <= a[hi]
                hi = lo
                so we have 
                a[lo - 1] < x <= a[lo]
                so we should return lo or hi
            
            case 2b: if "a[mid] < x" branch has never been executed
                lo is never changed
                x <= a[hi]
                hi = lo
                so we should return lo or hi
                
            case 3b: if "x <= a[mid]" branch has never been executed
                hi is never changed
                a[lo - 1] < x
                hi = lo
                so we should return lo or hi
                
    conclusion: we should return lo or hi                
                  
    """

    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    # Note, the comparison uses "<" to match the
    # __lt__() logic in list.sort() and in heapq.
    assert lo < hi
    if key is None:
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] < x:
                lo = mid + 1
            else:
                hi = mid
    else:
        while lo < hi:
            mid = (lo + hi) // 2
            if key(a[mid]) < x:
                lo = mid + 1
            else:
                hi = mid
                
    assert lo == hi
    
    return lo


# # Overwrite above definitions with a fast C implementation
# try:
#     from _bisect import *
# except ImportError:
#     pass

# # Create aliases
# bisect = bisect_right
# insort = insort_right


import random


def test_bisect_right():
    for i in range(1, 500):
        list_001 = random.choices(range(0, i), k= 3*i)
        list_001.sort()  
        # print(list_001)
        for x in list_001:
            # x = x + random.choice(range(-2, 2))
            insertion_index = bisect_right(list_001, x, 0, len(list_001))      
            assert 0 <= insertion_index <= len(list_001)
            if insertion_index >= 1:
                assert list_001[insertion_index - 1] <= x
            if insertion_index < len(list_001):
                assert list_001[insertion_index] > x


def test_bisect_left():
    for i in range(1, 500):
        list_001 = random.choices(range(0, i), k= 3*i)
        list_001.sort()  
        # print(list_001)
        for x in list_001:
            x = x + random.choice(range(-1000, 1000))
            insertion_index = bisect_left(list_001, x, 0, len(list_001))      
            assert 0 <= insertion_index <= len(list_001)
            if insertion_index >= 1:
                assert list_001[insertion_index - 1] < x
            if insertion_index < len(list_001):
                assert list_001[insertion_index] >= x       
                
if __name__ == '__main__':
    test_bisect_right()
    test_bisect_left()
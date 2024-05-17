def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        # array[1:] means from the second to the last value
        less = [i for i in array[1:] if i <= pivot]
        more = [i for i in array[1:] if i > pivot]

        return quicksort(less) + [pivot] + quicksort(more)
print(quicksort([10, 3, 54, 235, 31, 123, 45, 342, 1.24]))

from random import *
import sys
import time

def partition(A, start, end) :
    pivot = A[end]
    i = start-1
    for j in range(start, end) :
        if A[j] <= pivot :
            i = i+1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[end] = A[end], A[i+1]
    return i+1

def randomised_partition(A, start, end) :
    i = randint(start, end)
    A[end], A[i] = A[i], A[end]
    return partition(A, start, end)


def quicksort(A, start, end) :
    if end > start : # sort only if more than 1 element
        pivot = partition(A, start, end) # O(n)
        quicksort(A, start, pivot-1)
        quicksort(A, pivot+1, end)


if __name__ == '__main__':
    if len(sys.argv) != 2 :
        sys.exit('Usage: %s <number of elements>' % sys.argv[0])

    N = int(sys.argv[1])
    if N <= 0 :
        sys.exit('Usage: %s <number of elements>' % sys.argv[0])

    L = sample(range(1000000), N)
    start_time = time.process_time()
    for _ in range(1000) : 
        A = L.copy()
        quicksort(A, 0, N-1)
        for i in range(N-1) :
            assert A[i] <= A[i+1]
    end_time = time.process_time()

**DFS**
1. Good for balanced or dense trees that have less height and more nodes at a level
2. Less nodes have to store at once (nearly logN)

***A iterative dfs is far better than recursive stack***
1. Recursive DFS → limited by the call stack.
* Each recursive call creates a stack frame on the program's call stack. The call stack has a fixed size determined by the operating system (often around 1–8 MB by default, depending on platform and compiler settings).
* For a skewed tree with 100,000 nodes you create 100,000 stack frames. Eventually, the call stack runs out of space, causing a stack overflow.

2. Iterative DFS → limited by the heap.
* Here, the stack object itself is tiny (just a container object). Its elements are allocated from the heap (via the underlying container, typically deque).
* The heap is usually much larger than the call stack (hundreds of MBs or even GBs, depending on available memory). So even if you push 100,000 pointers, it's usually fine.

3. Note: They have the same Big-O because Big-O ignores where the memory is allocated.

**BFS**
1. Good for skewed or sparse trees where less nodes have to store at a level
2. Less nodes have to store at once (nearly constant - maxWidth)

**Case 1: Skewed tree**
```
1
 \
  2
   \
    3
     \
      4
```
Height = n
Max width = 1

Memory:
DFS = O(n) ❌
BFS = O(1) ✅

**Case 2: Complete tree**
```
          1
       /     \
      2       3
    /  \     /  \
   4   5    6    7
```

Last level has about n/2 nodes.

Memory:
DFS = O(log n) ✅
BFS = O(n) ❌

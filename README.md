# push_swap

A sorting program that outputs the shortest sequence of stack operations to sort a list of integers using only two stacks (`A` and `B`) and a limited set of moves.

---

## The Rules

You have **two stacks** and **11 allowed operations**:

| Operation | What it does |
|-----------|-------------|
| `sa` | Swap the top two elements of stack A |
| `sb` | Swap the top two elements of stack B |
| `ss` | `sa` + `sb` at the same time |
| `pa` | Push the top of B onto A |
| `pb` | Push the top of A onto B |
| `ra` | Rotate A upward (top goes to bottom) |
| `rb` | Rotate B upward |
| `rr` | `ra` + `rb` at the same time |
| `rra` | Reverse-rotate A (bottom goes to top) |
| `rrb` | Reverse-rotate B |
| `rrr` | `rra` + `rrb` at the same time |

The goal: print the list of operations that sorts the integers in ascending order on stack A.

---

## Project Structure

```
.
├── main.c               # Entry point, argument handling, error checking
├── parsing.c             # Input tokenization and validation
├── stack_operations.c    # Stack data structure (create, add, rotate, swap...)
├── operations.c          # Named operations (sa, pb, rr...) that print to stdout
├── algorithm.c           # Sorting driver and small-sort routines
├── target_node.c         # Target assignment, cost calculation, median tagging
├── moves.c               # Move execution (align + push), find_min/max, free
├── Push_swap.h           # Header with all structs and prototypes
├── libft/                # Custom C library (ft_split, ft_strjoin, ft_atoi...)
├── ft_printf/            # Custom printf implementation
└── Makefile
```

---

## Data Structures

### `t_stack` (doubly-linked list node)

```
┌──────────┬───────┬──────┬──────┬──────────┐
│  number  │ index │ prev │ next │ calcule  │
└──────────┴───────┴──────┴──────┴──────────┘
```

- **number** – the integer value stored in this node.
- **index** – position from the top of the stack (0 = top). Updated after every operation.
- **prev / next** – doubly-linked list pointers for O(1) access in both directions.
- **calcule** – pointer to a `t_cost` struct holding sorting metadata.

### `t_cost` (per-node sorting metadata)

```
┌──────┬──────────┬────────────┬────────┐
│ cost │ cheapest │ abv_median │ target │
└──────┴──────────┴────────────┴────────┘
```

- **cost** – total number of rotations needed to push this node to its correct position.
- **cheapest** – flag (1 = this node is the cheapest to move right now).
- **abv_median** – 1 if the node sits in the top half of its stack, 0 if bottom half. Determines whether we use `ra`/`rb` or `rra`/`rrb`.
- **target** – pointer to the node in the other stack where this node should land next to.

---

## The Algorithm (Step by Step)

The algorithm is a **cost-based greedy approach** (sometimes called the "Turkish" algorithm). It works in 4 phases:

### Phase 0 — Edge Cases

If there are **1 or fewer** elements, do nothing.  
If there are exactly **2** elements and they're out of order, just `sa`.  
If the stack is already sorted, exit immediately.

### Phase 1 — Push A → B (keep 3 in A)

1. Push the first two elements to B unconditionally (we need at least 2 in B for targeting to work).
2. For every remaining element beyond 3 in A:
   - **Tag the median**: walk both stacks and mark each node as "above median" (top half) or "below median" (bottom half).
   - **Assign targets**: for each node in A, find the **closest smaller value** in B. If none exists, target the **largest** value in B (wrapping around the sorted order).
   - **Calculate cost**: for each A node, compute how many rotations it takes to bring both the node and its target to the top of their respective stacks.
   - **Pick the cheapest**: mark the node with the lowest cost.
   - **Align and push**: rotate both stacks to position the cheapest node and its target at the top, then `pb`.

#### Cost Calculation Details

The cost depends on where the node and its target sit relative to the median:

| Node position | Target position | Cost | Why |
|---|---|---|---|
| Top half | Top half | `max(index_a, index_b)` | Use `rr` to rotate both simultaneously |
| Bottom half | Bottom half | `max(size_a - index_a, size_b - index_b)` | Use `rrr` to reverse-rotate both simultaneously |
| Top half | Bottom half | `index_a + (size_b - index_b)` | Must rotate independently |
| Bottom half | Top half | `(size_a - index_a) + index_b` | Must rotate independently |

The key optimization: when both nodes are on the **same side**, we combine rotations (`rr` or `rrr`), which effectively halves the cost.

### Phase 2 — Sort the remaining 3 in A

With only 3 elements left in A, use a hardcoded `sort_three`:
1. If the **largest** is on top → `ra` (send it to the bottom).
2. If the **largest** is in the middle → `rra` (bring the bottom up).
3. If the top two are still out of order → `sa`.

This sorts any 3-element permutation in at most **2 operations**.

### Phase 3 — Push B → A

For each element in B (processed one at a time from the top):
1. **Assign a target in A**: find the **closest larger value** in A. If none exists, target the **smallest** (wrapping around).
2. **Tag the median** in A so we know which direction to rotate.
3. **Rotate A** until the target sits on top.
4. `pa` to push the B element into position.

### Phase 4 — Final Rotation

After all elements are back in A, the stack is sorted but the minimum may not be on top. Find the smallest element, check whether it's in the top or bottom half, and rotate (`ra` or `rra`) until it reaches position 0.

---

## Visualizing the Flow

```
Input: 5 3 1 4 2

Stack A: [5, 3, 1, 4, 2]    Stack B: []

Phase 1: Push to B
  pb → A: [3, 1, 4, 2]      B: [5]
  pb → A: [1, 4, 2]         B: [3, 5]
  (initialize + cheapest move)
  ...push until A has 3 left

Phase 2: sort_three on A
  A: [1, 2, 4]              B: [5, 3]   (example state)

Phase 3: Push back to A
  (target for B-top=5 → smallest in A=1, rotate A to 1)
  pa → A: [5, 1, 2, 4]      B: [3]
  (target for B-top=3 → closest larger=4, rotate A to 4)
  pa → A: [3, 4, 5, 1, 2]   B: []

Phase 4: Rotate minimum to top
  rra → A: [2, 3, 4, 5, 1]
  rra → A: [1, 2, 3, 4, 5]  ✓ Sorted!
```

---

## Optimizations Summary

| Optimization | Effect |
|---|---|
| **Combined rotations** (`rr`/`rrr`) | When both nodes are on the same side, one operation moves both stacks — roughly halving the cost |
| **Median-based direction** | Always rotate in the cheaper direction (forward if above median, backward if below) |
| **Greedy cheapest-first** | Each iteration picks the single cheapest node to move, minimizing total operations |
| **Early exit** | If the stack is already sorted at any point, stop immediately |
| **Hardcoded sort_three** | 3 elements are sorted in at most 2 operations with no overhead |
| **Index tracking** | Every node stores its position; updated after each operation for O(1) cost lookups |

---

## Performance

| Input size | Operations (avg) | Limit |
|---|---|---|
| 2 | 0–1 | — |
| 3 | 1–2 | 3 |
| 5 | ~8 | 12 |
| 100 | ~570 | 700 |
| 500 | ~5100 | 5500 |

---

## Usage

```bash
# Build
make

# Run
./push_swap 4 2 7 1 3

# Count operations
./push_swap 4 2 7 1 3 | wc -l

# Verify with checker (if available)
./push_swap 4 2 7 1 3 | ./checker 4 2 7 1 3

# Clean
make fclean
```

### Error Handling

The program prints `Error` to stderr and exits with code 1 for:
- Non-integer arguments
- Values outside the 32-bit integer range
- Duplicate values
- Empty input strings

If the input is already sorted or has only one element, nothing is printed.

---

## File-by-File Breakdown

| File | Responsibility |
|---|---|
| **main.c** | Argument tokenization, stack creation, error handling, calling the sorter, cleanup |
| **parsing.c** | `extract_string` joins argv into one string; `input_validator` checks every token is a valid integer |
| **stack_operations.c** | Low-level stack primitives: `ft_stack_new` (allocates node + cost struct), `stack_rotate`, `stack_rev_rotate`, `stack_swap`, `update_index`, `populate_stack`, `stack_dup_check` |
| **operations.c** | Wrapper functions that call the primitive + print the operation name (`sa`, `pb`, `rr`, etc.) |
| **algorithm.c** | `sort_stack` (main driver), `sort_three`, `fix_sorted_stack`, `stack_is_sorted`, `check_sorted` |
| **target_node.c** | `median_cmp`, `choose_target_a/b`, `calc_costs`, `initialize_nodes_a/b` |
| **moves.c** | `align_top` (combined rotation logic), `move_a_to_b`, `move_b_to_a`, `find_largest`, `find_smallest`, `free_stack` |

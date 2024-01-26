module core.interval;

import core.vector;

struct Interval(T) {
    ulong start;
    ulong size;
    T val;

    bool overlaps(ulong other_start, ulong other_size) {
        return start < other_start + other_size && start + size > other_start;
    }
}

// TODO: implement this as an actual interval tree
struct IntervalTree(T) {
    Vector!(Interval!(T)) intervals;

    // Add a new interval.
    bool add(ulong start, ulong size, T val) {
        return intervals.append(Interval!(T)(start, size, val));
    }

    // Remove the interval at the given location.
    bool remove(ulong start, ulong size) {
        for (usize i = 0; i < intervals.length; i++) {
            if (intervals[i].start == start && intervals[i].size == size) {
                intervals.unordered_remove(i);
                return true;
            }
        }
        return false;
    }

    // Check if the given interval overlaps any intervals in the tree.
    bool overlaps(ulong start, ulong size, ref Interval!(T) val) {
        foreach (ref i; intervals) {
            if (i.overlaps(start, size)) {
                val = i;
                return true;
            }
        }
        return false;
    }

    // Finds an interval with size at least 'size'.
    bool find(ulong size, ref Interval!(T) val) {
        foreach (ref i; intervals) {
            if (i.size >= size) {
                val = i;
                return true;
            }
        }
        return false;
    }

    // Finds an interval with matching start and size.
    bool find_exact(ulong start, ulong size, ref Interval!(T) val) {
        foreach (ref i; intervals) {
            if (i.start == start && i.size == size) {
                val = i;
                return true;
            }
        }
        return false;
    }
}

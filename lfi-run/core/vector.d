module core.vector;

import core.alloc;
import core.lib : memcpy;

struct Vector(T) {
    T[] data;
    usize length;

    T[] array() {
        return data[0 .. length];
    }

    ref T opIndex(usize i) {
        assert(i < length, "vector index out of bounds");
        return data[i];
    }

    usize cap() {
        return data.length;
    }

    void clear() {
        kfree(data);
        length = 0;
        data = null;
    }

    bool grow() {
        // double in size by default
        return grow(cap == 0 ? 8 : cap * 2);
    }

    bool grow(usize newlen) {
        T* p = cast(T*) kalloc(newlen * T.sizeof);
        if (!p) {
            return false;
        }
        memcpy(p, data.ptr, data.length * T.sizeof);
        kfree(data);
        data = cast(T[]) p[0 .. newlen];
        return true;
    }

    bool append(T value) {
        if (!data || length >= cap) {
            if (!grow()) {
                return false;
            }
        }
        assert(length < cap);
        data[length++] = value;
        return true;
    }

    Range!T range() {
        return Range!T(0, this);
    }

    void unordered_remove(usize idx) {
        assert(idx < length, "vector index out of bounds");
        data[idx] = data[length - 1];
        length--;
    }

    alias range this;

    struct Range(T) {
        usize i;
        Vector!(T) vec;

        bool empty() {
            return i >= vec.length;
        }

        ref T front() {
            return vec[i];
        }

        void popFront() {
            i++;
        }
    }
}

module buddy;

extern (C):

void* buddy_init_alignment(ubyte* at, void* main, usize mem_size, usize alignment);
void* buddy_malloc(void* buddy, usize size);
usize buddy_sizeof_alignment(usize mem_size, usize alignment);
bool buddy_safe_free(void* buddy, void* ptr, usize size);
bool buddy_is_full(void* buddy);
void* buddy_copy(ubyte* at, void* main, void* from);
void buddy_reserve_range(void* buddy, void* ptr, usize requested_size);
void buddy_unsafe_release_range(void* buddy, void* ptr, usize requested_size);

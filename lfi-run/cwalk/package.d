module cwalk;

extern (C):

usize cwk_path_join(const(char)* path_a, const(char)* path_b, char* buffer, usize buffer_size);
bool cwk_path_is_absolute(const(char)* path);

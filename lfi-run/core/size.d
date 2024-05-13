module core.size;

enum gb(ulong n) = 1024 * 1024 * 1024 * n;
enum mb(ulong n) = 1024 * 1024 * n;
enum kb(ulong n) = 1024 * n;

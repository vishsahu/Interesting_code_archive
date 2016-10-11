#define tester;

typedef int datatype;
typedef int limit;

// randomized partition of given array
limit rand_partition(datatype *a, limit p, limit r);

//interface for quick sort
void quick_sort(datatype *a, limit p, limit r);

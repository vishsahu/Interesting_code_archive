#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* First we need to allocate memory of size bytes + alignment + sizeof(size_t) .
    'bytes'    : user requested it,
    'alignment': because malloc can give us any address and we need to find
                multiple of 'alignment', so at maximum multiple of alignment
                will be 'alignment' bytes away from any location.
    'sizeof(size_t)': for implementing 'aligned_free', since we are returning
                modified memory pointer, not given by malloc ,to the user, we
                must free the memory allocated by malloc not anything else. So
                I am storing address given by malloc just above pointer
                returning to user in 'backup_point'.

    To test if the code is correct or not:

    user@pc:/foo$ gcc aligned_malloc.c
    user@pc:/foo$ valgrind ./a.out

*/
void* aligned_malloc(size_t size, size_t alignment) {
    void* internal = malloc(size + alignment + sizeof(size_t));
    size_t val_internal = (size_t)internal;
    size_t value = val_internal + alignment + sizeof(size_t);
    void* aligned_addr = (void *)(value - (value % alignment));
    void* backup_point = aligned_addr - sizeof(size_t);
    printf("original addr=%p, aligned addr=%p, backup pt=%p\n", internal, aligned_addr, backup_point);
    memcpy(backup_point, &internal, sizeof(size_t));
    printf("value stored=%p, %x\n", *((size_t *)backup_point), *((size_t *)backup_point));
    return aligned_addr;
}

void aligned_free(void *ptr) {
    free((void *)(*((size_t *)ptr - 1)));
}

int main(void) {
    // test function
    void *foo = NULL;
    foo = aligned_malloc(25, 16);
    printf("got allocated at %x, error = %lu\n", (unsigned int)foo, (size_t)foo % 16);
    aligned_free(foo);

    foo = aligned_malloc(425, 8);
    printf("got allocated at %x, error = %lu\n", (unsigned int)foo, (size_t)foo % 8);
    aligned_free(foo);

    foo = aligned_malloc(2545, 24);
    printf("got allocated at %x, error = %lu\n", (unsigned int)foo, (size_t)foo % 24);
    aligned_free(foo);

    foo = aligned_malloc(2345, 4);
    printf("got allocated at %x, error = %lu\n", (unsigned int)foo, (size_t)foo % 4);
    aligned_free(foo);

    foo = aligned_malloc(4332, 16);
    printf("got allocated at %x, error = %lu\n", (unsigned int)foo, (size_t)foo % 16);
    aligned_free(foo);
    return 0;
}

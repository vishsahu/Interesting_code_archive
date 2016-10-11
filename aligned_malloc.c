#include <stdio.h>
#include <stdlib.h>
/* implement properly considering the memory leaks */
int main(void) {
    void *mem = NULL;
    size_t size=20;
    size_t alignment = 16;
    size_t word_size = sizeof(int);
    size_t addr_required = size / word_size;
    size_t allocated = addr_required * word_size + alignment;

    mem = malloc(allocated);
    size_t offset = (size_t)mem;
    if ((size_t)mem % alignment) {
        printf("is not aligned\n");
        offset = ((size_t)mem / alignment) * alignment + alignment;
    }

    printf("Requested: %u Allocated %u bytes at %x, %x\n", size, allocated, mem, offset);
    free(mem);
    return 0;
}

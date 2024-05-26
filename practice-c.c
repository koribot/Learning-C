#include <stdio.h>
#include <stdlib.h>
typedef struct meta_block *meta_ptr;
struct meta_block
{
  int free;
  size_t size;
  meta_ptr next;
  meta_ptr prev;
  void *ptr;
  char *data;
};

meta_ptr create_meta_block(int free, size_t size, meta_ptr next, meta_ptr prev, void *ptr, char data[])
{
  meta_ptr block = malloc(sizeof(struct meta_block));
  if (block != NULL)
  {
    block->free = free;
    block->size = size;
    block->next = next;
    block->prev = prev;
    block->ptr = ptr;
    block->data = data;
  }
  return block;
}

int main()
{
  meta_ptr ptr = create_meta_block(1, sizeof(struct meta_block), NULL, NULL, NULL, "Hello");
  // int n;
  // int *ptr;
  // int **pptr;
  // int ***ppptr;

  // n=42;
  // ptr = &n;
  // pptr = &ptr;
  // ppptr = &pptr;

  // printf("%p == %p == %p == %p\n ", **ppptr, *pptr, ptr, &n);
  // int c = 5;
  // int *b = &c;
  // printf("%p == %p\n", b, &c);
  // int num = 55;
  // int *pptr = &num;  // Assign the address of num to pptr
  // *pptr = 55;  // Now dereferencing pptr and assigning 55 to num is valid

  printf("Address where meta_ptr is stored: %s\n", ptr);
  if (ptr != NULL)
  {
    printf("Address where meta_ptr is stored: %p\n", (void *)ptr);
    printf("Contents of the struct:\n");
    printf("free: %d\n", ptr->free);
    printf("size: %zu\n", ptr->size);
    printf("next: %p\n", (void *)ptr->next);
    printf("prev: %p\n", (void *)ptr->prev);
    printf("ptr: %p\n", ptr->ptr);
    printf("data: %s\n", ptr->data);
  }
  else
  {
    printf("Memory allocation failed\n");
  }

  return 0;
}
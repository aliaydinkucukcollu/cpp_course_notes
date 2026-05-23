#include <stdio.h>
#include <string.h>

// WITHOUT restrict - compiler cannot assume no aliasing
void add_arrays(int *a, int *b, int *result, int n) {
  for (int i = 0; i < n; i++) {
    result[i] = a[i] + b[i]; // compiler must reload a[i]/b[i] each iteration
  }                          // in case result overlaps with a or b
}

// WITH restrict - compiler knows pointers don't alias each other
void add_arrays_restrict(int *restrict a, int *restrict b, int *restrict result,
                         int n) {
  for (int i = 0; i < n; i++) {
    result[i] =
        a[i] + b[i]; // compiler can optimize freely (vectorize, cache values)
  }
}

// Classic example: memcpy vs memmove
// memcpy uses restrict - src and dst must NOT overlap
void *my_memcpy(void *restrict dst, const void *restrict src, size_t n) {
  char *d = dst;
  const char *s = src;
  while (n--)
    *d++ = *s++;
  return dst;
}

// memmove does NOT use restrict - handles overlapping memory safely
void *my_memmove(void *dst, const void *src, size_t n) {
  char *d = dst;
  const char *s = src;
  if (d < s) {
    while (n--)
      *d++ = *s++; // copy forward
  } else {
    d += n;
    s += n;
    while (n--)
      *--d = *--s; // copy backward to handle overlap
  }
  return dst;
}

// Demonstrating the aliasing problem restrict solves
void scale_add(float *restrict out, const float *restrict in, float scale,
               int n) {
  for (int i = 0; i < n; i++) {
    out[i] = in[i] * scale + in[i]; // safe to read in[i] once; compiler knows
  }                                 // out and in don't overlap
}

int main() {
  int a[] = {1, 2, 3, 4};
  int b[] = {10, 20, 30, 40};
  int result[4];

  add_arrays_restrict(a, b, result, 4);

  printf("Result: ");
  for (int i = 0; i < 4; i++)
    printf("%d ", result[i]);
  printf("\n"); // Output: 11 22 33 44

  // UNDEFINED BEHAVIOR example (don't do this):
  add_arrays_restrict(a, a, result, 4); // 'a' passed for two restrict params!

  printf("Result: ");
  for (int i = 0; i < 4; i++)
    printf("%d ", result[i]);
  printf("\n"); // Output: 11 22 33 44

  char src[] = "Hello, World!";
  char dst[20];
  my_memcpy(dst, src, strlen(src) + 1);
  printf("Copied: %s\n", dst); // Output: Hello, World!

  return 0;
}
#include <stdint.h>
#include <stdio.h>

struct illusionDriftState8 {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
};

uint8_t illusionDrift8(struct illusionDriftState8 *s) {
  uint8_t mix = s->a ^ s->b;

  s->a += 111;
  s->b = s->c;
  s->c = s->d;
  s->d = ((s->d << 3) | (s->d >> 5)) + mix;
  return mix;
}

int main(void) {
  struct illusionDriftState8 s;
  unsigned short i = 0;
  unsigned short j;
  uint32_t k;

  while (i < 256) {
    j = 0;

    while (j < 256) {
      s.a = 0;
      s.b = 0;
      s.c = i;
      s.d = j;
      illusionDrift8(&s);
      k = 1;

      while (k < 65536) {
        if (
          s.a == 0 &&
          s.b == 0 &&
          s.c == i &&
          s.d == j
        ) {
          break;
        }

        illusionDrift8(&s);
        k++;
      }

      if (k != 65536) {
        return 1;
      }

      j++;
    }

    i++;
  }

  printf("It generates a period of at least 2¹⁶.\n");
  return 0;
}

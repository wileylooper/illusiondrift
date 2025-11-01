#include <stdint.h>

struct illusionDriftState64 {
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

struct illusionDriftState32 {
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t d;
};

struct illusionDriftState8 {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
};

uint64_t illusionDrift64(struct illusionDriftState64 *s) {
  uint64_t mix = s->a ^ s->b;

  s->a += 111111111111111111;
  s->b = s->c;
  s->c = s->d;
  s->d = ((s->d << 21) | (s->d >> 43)) + mix;
  return mix;
}

uint32_t illusionDrift32(struct illusionDriftState32 *s) {
  uint32_t mix = s->a ^ s->b;

  s->a += 111111111;
  s->b = s->c;
  s->c = s->d;
  s->d = ((s->d << 9) | (s->d >> 23)) + mix;
  return mix;
}

uint8_t illusionDrift8(struct illusionDriftState8 *s) {
  uint8_t mix = s->a ^ s->b;

  s->a += 111;
  s->b = s->c;
  s->c = s->d;
  s->d = ((s->d << 3) | (s->d >> 5)) + mix;
  return mix;
}

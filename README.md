#### IllusionDrift64

IllusionDrift64 provides enhanced parallelism, period, speed and statistical test results as an ideal alternative to Xoroshiro128+, Xorshift128 and Xorshift128+.

It has a period of at least 2¹²⁸.

Seeding `d` with non-overlapping integers and seeding the remaining state with `0` behaves as a jump function with up to 2⁶⁴ parallel instances that each have a non-overlapping period of at least 2⁶⁴. The first several results from each parallel instance should be skipped.

In non-parallel instances, `c` and `d` must each be assigned a seed and the remaining state must be seeded with `0`. The first few results from each non-parallel instance should be skipped.

`illusionDrift64` generates and returns a pseudorandom `uint64_t` integer, provided the implementation supports a 64-bit, unsigned integral type for `uint64_t`.

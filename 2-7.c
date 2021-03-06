// 2.7 : invert bits

#include <stdio.h>

void putd(int d) {
  printf("%d\n", d);
}

// Get n bits from position p in x
unsigned int getbits(unsigned int x, int p, int n) {
  // return (x >> (p + 1 - n)) & ~(~0 << n);

  // x = 111000

  // Move desired bit range to the end of the word
  unsigned int right_adjusted_word = x >> (p + 1 - n); // x = 56 = 00001110

  unsigned int all_ones = ~0; // Do this to make it independent of word size? Maybe not...
  unsigned int zeros_in_right_n_bits = all_ones << n; // 11111000
  unsigned int ones_in_right_n_bits = ~zeros_in_right_n_bits; // 00000111

  // Mask bits to ignore more significant bits
  unsigned int bits_in_range = right_adjusted_word & ones_in_right_n_bits; // 00000110 = 6

  return bits_in_range;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // mask = value with range of bits to be changed set to 1
  // value = (value & ~mask) | (newvalue & mask)

  // 111000, 4, 3, 101
  unsigned desired_bits = getbits(y, n - 1, n); // 101
  unsigned correctly_positioned_bits = desired_bits << (p + 1 - n); // 10100
  unsigned mask = (~(~0 << n)) << (p + 1 - n); //correctly_positioned_bits | 0; // 11100

  unsigned ret = (x & ~mask) | (correctly_positioned_bits & mask); //110100
  return ret;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned bits_to_invert = getbits(x, p, n);
  unsigned x_with_inverted_bits = setbits(x, p, n, ~bits_to_invert);
  return x_with_inverted_bits;
}

int main() {
  putd(invert(56, 4, 3)); // 36
  putd(invert(340, 6, 4)); // 300
  return 0;
}

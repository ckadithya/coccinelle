#include <stdio.h>

#define WRITEMASK(x) (1u<<x)
#define READMASK(x) (~(1u<<x))

//referred from http://learn.parallax.com/tutorials/language/
//..propeller-c/propeller-c-simple-protocols/spi-example/bit-masks-better-code
int main(int i) {
  int cmd   = 0x0;
  
  const int MCTL  = 0x16;        // = 0b0100101  // Control register address
  const int ZOUT8 = 0x08;        // = 0b0001000  // 8-bit z register address

  printf("MCTL      = %04x \n", MCTL);           // Display binary MCTL address
  printf("writeMask = %04x (OR)\n", (1u<<6));    // Display binary writeMask

  cmd = MCTL | (1u<<6);                          // MCTL OR writeMask to cmd

  printf("-------------------------\n");         // Draw line
  printf("cmd       = %04x \n\n", cmd);          // Display cmd result
  printf("ZOUT8     = %04x \n", ZOUT8);          // Display binary ZOUT address
  printf("readMask  = %04x (AND)\n",             // Display binary readMask
        ~(1u<<6) & 0b1111111);                   // Bits 31...7 -> 0 for display

  cmd = ZOUT8 & ~(1u<<6);                        // ZOUT8 AND readMask to cmd

  printf("-------------------------\n");         // Draw line
  printf("cmd       = %04x \n", cmd);            // Display cmd result
  return 0;
}

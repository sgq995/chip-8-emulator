#include <stdint.h>

#include "common.h"

int main(int argc, char **argv) {
  UNUSED(argc);
  UNUSED(argv);

  uint16_t opcode;

  uint8_t memory[4096];
  uint8_t V[16];

  uint16_t I;
  uint16_t PC;

  uint8_t gfx[64 * 32];

  uint8_t delay_timer;
  uint8_t sound_timer;

  uint8_t stack[48];
  uint16_t SP;

  uint8_t keyboard[16];

  while (1) {
    // TODO: emulation cycle
  }

  return 0;
}

#include "cpu.h"

#include <string.h>

#include "mmu.h"

void cpu_init(cpu_t *cpu) {
  memset(cpu->V, 0, sizeof(cpu->V));

  cpu->I  = 0;
  cpu->PC = MMU_PROGRAM_START;

  cpu->SP = 0;
}

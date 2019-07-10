#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>

#include "mmu.h"

#define CPU_MAX_DATA_REGISTERS (16)

typedef struct cpu {
  uint8_t V[CPU_MAX_DATA_REGISTERS];

  uint16_t I;
  uint16_t PC;

  uint16_t SP;
} cpu_t;

void cpu_init(cpu_t *cpu);

#endif  /* CPU_H_ */

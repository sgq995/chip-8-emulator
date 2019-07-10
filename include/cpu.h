#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>

#include "mmu.h"

#define CPU_MAX_DATA_REGISTERS (16)

#define CPU_OPCODE_MASK (0xF000)

typedef struct cpu {
  uint8_t V[CPU_MAX_DATA_REGISTERS];

  uint16_t I;
  uint16_t PC;

  uint16_t SP;
} cpu_t;

void cpu_init(cpu_t *cpu);

uint16_t cpu_program_counter_step(cpu_t *cpu);

void cpu_run(cpu_t *cpu, mmu_t *mmu, uint16_t opcode);

#endif  /* CPU_H_ */

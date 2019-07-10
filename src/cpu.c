#include "cpu.h"

#include <assert.h>
#include <string.h>

#include "mmu.h"

void cpu_init(cpu_t *cpu) {
  assert(cpu != NULL);

  memset(cpu->V, 0, sizeof(cpu->V));

  cpu->I  = 0;
  cpu->PC = MMU_PROGRAM_START;

  cpu->SP = 0;
}

uint16_t cpu_program_counter_step(cpu_t *cpu) {
  uint16_t PC = cpu->PC;
  cpu->PC++;
  return PC;
}

void cpu_run(cpu_t *cpu, mmu_t *mmu, uint16_t opcode) {
  uint16_t opcode_set = (opcode & CPU_OPCODE_MASK) >> 12;
  uint16_t opcode_subset;

  uint16_t address;

  uint8_t vx_idx;
  uint8_t vy_idx;

  uint8_t value;

  int16_t result;

  switch (opcode_set) {
    case 0x0:
      opcode_subset = opcode & 0xFF;
      switch (opcode_subset) {
        case 0xE0:
          // TODO: celar screen
          break;

        case 0xEE:
          // TODO: return from subroutine
          break;

        default:
          break;
      }
      break;

    case 0x1:
      address = opcode & 0x0FFF;
      // TODO: jump to address
      break;

    case 0x2:
      address = opcode & 0x0FFF;
      // TODO: call subroutine at address
      break;

    case 0x3:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      value  = opcode & 0x00FF;

      if (cpu->V[vx_idx] == value) {
        cpu_program_counter_step(cpu);
      }
      break;

    case 0x4:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      value  = opcode & 0x00FF;

      if (cpu->V[vx_idx] != value) {
        cpu_program_counter_step(cpu);
      }
      break;

    case 0x5:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      vy_idx = (uint8_t)((opcode & 0x00F0) >> 4);

      if (cpu->V[vx_idx] == cpu->V[vy_idx]) {
        cpu_program_counter_step(cpu);
      }
      break;

    case 0x6:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      value  = opcode & 0x00FF;

      cpu->V[vx_idx] = value;
      break;

    case 0x7:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      value  = opcode & 0x00FF;

      cpu->V[vx_idx] += value;
      break;

    case 0x8:
      vx_idx = (uint8_t)((opcode & 0x0F00) >> 8);
      vy_idx = (uint8_t)((opcode & 0x00F0) >> 4);

      opcode_subset = opcode & 0x000F;
      switch (opcode_subset) {
        case 0x0:
          cpu->V[vx_idx] = cpu->V[vy_idx];
          break;

        case 0x1:
          cpu->V[vx_idx] |= cpu->V[vy_idx];
          break;

        case 0x2:
          cpu->V[vx_idx] &= cpu->V[vy_idx];
          break;

        case 0x3:
          cpu->V[vx_idx] ^= cpu->V[vy_idx];
          break;

        case 0x4:
          result = (int16_t)(cpu->V[vx_idx] + cpu->V[vy_idx]);
          if (result > 255) {
            result &= 0xFF;
            cpu->V[0xF] = 1;
          } else {
            cpu->V[0xF] = 0;
          }
          cpu->V[vx_idx] = (uint8_t)result;
          break;

        case 0x5:
          result = (int16_t)(cpu->V[vx_idx] - cpu->V[vy_idx]);
          if (result < 0) {
            result &= 0xFF;
            cpu->V[0xF] = 0;
          } else {
            cpu->V[0xF] = 1;
          }
          cpu->V[vx_idx] = (uint8_t)result;
          break;

        default:
          break;
      }
      break;

    case 0x9:
      break;

    case 0xA:
      break;

    case 0xB:
      break;

    case 0xC:
      break;

    case 0xD:
      break;

    case 0xE:
      break;

    case 0xF:
      break;

    default:
      break;
  }
}

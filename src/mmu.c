#include "mmu.h"

#include <assert.h>
#include <string.h>

void mmu_init(mmu_t *mmu) {
  assert(mmu != NULL);

  memset(mmu->memory, 0, sizeof(mmu->memory));

  // TODO: load fontset
}

uint8_t mmu_load_8bit(mmu_t *mmu, uint16_t address) {
  assert(mmu != NULL);
  assert(address < sizeof(mmu->memory));

  return mmu->memory[address];
}

void mmu_save_8bit(mmu_t *mmu, uint16_t address, uint8_t value) {
  assert(mmu != NULL);
  assert(address < sizeof(mmu->memory));

  mmu->memory[address] = value;
}

uint16_t mmu_load_16bit_be(mmu_t *mmu, uint16_t address) {
  assert(mmu != NULL);
  assert(address < sizeof(mmu->memory));

  return (uint16_t)((mmu->memory[address] << 8) | (mmu->memory[address + 1]));
}

void mmu_save_16bit_be(mmu_t *mmu, uint16_t address, uint16_t value) {
  assert(mmu != NULL);
  assert(address < sizeof(mmu->memory));

  mmu->memory[address]     = (uint8_t)((value >> 8) & 0xFF);
  mmu->memory[address + 1] = (uint8_t)((value     ) & 0xFF);
}

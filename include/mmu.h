#ifndef MMU_H_
#define MMU_H_

#include <stdint.h>

#define MMU_MEMORY_SIZE (4096)

#define MMU_INTERPRETER_START (0x000)
#define MMU_INTERPRETER_END   (0x1FF)

#define MMU_BUILTIN_FONT_START (0x050)
#define MMU_BUILTIN_FONT_END   (0x0A0)

#define MMU_PROGRAM_START (0x200)

#define MMU_CALL_STACK_START (0xEA0)
#define MMU_CALL_STACK_END   (0xEFF)

#define MMU_DISPLAY_REFRESH_START (0xF00)
#define MMU_DISPLAY_REFRESH_END   (0xFFF)

typedef struct mmu {
  uint8_t memory[MMU_MEMORY_SIZE];
} mmu_t;

void mmu_init(mmu_t *mmu);

uint8_t mmu_load_8bit(mmu_t *mmu, uint16_t address);

void mmu_save_8bit(mmu_t *mmu, uint16_t address, uint8_t value);

uint16_t mmu_load_16bit_be(mmu_t *mmu, uint16_t address);

void mmu_save_16bit_be(mmu_t *mmu, uint16_t address, uint16_t value);

#endif  /* MMU_H_ */

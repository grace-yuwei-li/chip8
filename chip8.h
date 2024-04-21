#include <cstdint>
#ifndef CHIP8_H
#define CHIP8_H

// Define the CHIP-8 class and its methods...
class Test;
class Chip8 {

public:
    // Chip8();
    // ~Chip8();

    bool loadROM(const char* romFilePath);
    void run();

private:
    friend class Test;
    uint32_t registers[16];
    uint8_t memory[4096];

    bool display[64][32];

    uint8_t V[16];
    uint16_t I;

    uint16_t PC;

    uint16_t stack[16];
    uint8_t stackPointer;

    uint8_t delayTimer;
    uint8_t soundTimer;

    bool key[16];

    void executeOpcode(uint16_t opcode);

    uint16_t fetchOpcode();
    uint16_t decodeOpcode(uint16_t opcodde);

    uint8_t readMemory(uint16_t address);
    void writeMemory(uint16_t address, uint8_t value);

    void updateDisplay();
    void updateInput();
    void generateSound();
    void clearScreen();

    void pushStack(uint16_t address);
    uint16_t popStack();

    void initializeMemory();
};

#endif
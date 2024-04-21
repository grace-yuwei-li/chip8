#include "Chip8.h"

const uint8_t CHIP8_FONT[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void Chip8::initializeMemory() {
    for (int i = 0; i < 80; i++) {
        memory[0x050 + i] = CHIP8_FONT[i];
    }
}

// void Chip8::drawSprite(uint8_t x, uint8_t y, uint8_t height, uint8_t* spriteData) {

// }

// uint16_t Chip8::decodeOpcode(uint16_t opcode) {

//     return;
// }

void Chip8::executeOpcode(uint16_t opcode) {
    // uint16_t instruction = decodeOpcode(opcode);

    uint8_t firstNibble = (opcode & 0xF000) >> 12;
    // uint8_t X = (instruction & 0x0F00) >> 8;
    // uint8_t Y = (instruction & 0x00F0) >> 4;
    // uint8_t N = instruction & 0x000F;
    // uint8_t NN = instruction & 0x00FF;
    // uint16_t NNN = instruction & 0x0FFF;

    switch (firstNibble) {
        case 0x0:
            if (opcode == 0x00E0) {
                // clear screen
                clearScreen();
            } else if (opcode == 0x00EE) {
                //return from subroutine
                // PC = popStack();
            } else {
                // something
            }
            break;
        // case 0x1:
        //     PC = NNN;
        //     break;
        // case 0x6:
        //     V[X] = NN;
        //     break;
        // case 0x7:
        //     V[Y] += NN;
        //     break;
        // case 0xA:
        //     I = NNN;
        //     break;
        // case 0xD:
        //     // drawSprite(V[X], V[Y], N, &memory[I]);
        //     break;
        default:
            break;
    }
    return;
}

void Chip8::clearScreen() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 32; j++) {
            display[i][j] = false;
        }
    }
}
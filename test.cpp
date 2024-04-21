#include "chip8.h"
// #include "chip8.cpp"
#include <cassert>

class Test {
public:
    void testPrivateFunctions() {
        testClearScreen();
    }

    void testClearScreen() {
        Chip8 chip8;

        chip8.clearScreen();

        chip8.executeOpcode(0x00E0);

        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 32; ++j) {
                assert((chip8.display[i][j] == true) && "Debug");
            }
        }
    }

};

int main() {
    Test test;
    test.testPrivateFunctions();
    return 0;
}
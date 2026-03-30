00001100  // Cycle 1: Load x[0] into R3 (Pointer R1++ automatically)
00000010  // Cycle 2: Load y[0] into R0 (Pointer R2++ automatically)
01000011  // Cycle 3: DIV R0, R3 (h[0] calculated)
00010011  // Cycle 4: STORE h[0] (Pointer R3++ automatically)
00000010  // Cycle 5: Load y[1] into R0
00110010  // Cycle 6: SMAC (R0 - R1*R2) -- Using the auto-incremented x[1] and h[0]
01000011  // Cycle 7: DIV
00010011  // Cycle 8: STORE h[1]
11110000  // HALT
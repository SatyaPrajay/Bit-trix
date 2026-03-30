# Updated for Deconvolution math
OPCODES = {
    "LOAD_RAM":  "0000",
    "STORE_RAM": "0001",
    "SUB":       "0010",
    "MAC":       "0011", # R0 = R0 - (R1 * R2)
    "DIV":       "0100", # R0 = R0 / R3
    "LI":        "0101", # Load Immediate/NOP
    "HALT":      "1111",
}

REGS = {
    "R0": "00", "R1": "01", "R2": "10", "R3": "11",
}

# The actual Deconvolution Program for h[0] and h[1]
# Assume RAM: x[0]=addr 0, x[1]=addr 1, y[0]=addr 10, y[1]=addr 11, h starts at 20
program = [
    ("LOAD_RAM", "R3", "R0"), # Load x[0] into R3 (Divisor) - Note: Addr 0 is usually R0
    
    # Compute h[0] = y[0] / x[0]
    ("LOAD_RAM", "R0", "R1"), # Load y[0] into R0
    ("DIV",      "R0", "R3"), # R0 = R0 / R3
    ("STORE_RAM","R0", "R2"), # Store h[0] at addr 20
    
    # Compute h[1] = (y[1] - h[0]*x[1]) / x[0]
    ("LOAD_RAM", "R0", "R1"), # Load y[1] into R0
    ("LOAD_RAM", "R1", "R2"), # Load h[0] into R1
    ("LOAD_RAM", "R2", "R1"), # Load x[1] into R2
    ("MAC",      "R1", "R2"), # R0 = R0 - (R1 * R2) -- Custom Subtractive MAC
    ("DIV",      "R0", "R3"), # R0 = R0 / R3
    ("STORE_RAM","R0", "R2"), # Store h[1]
    
    ("HALT",     "R0", "R0"),
]

# ... (Keep the rest of your print/write logic the same)
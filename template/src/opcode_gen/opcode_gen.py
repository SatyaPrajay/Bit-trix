# opcode_gen.py
OPCODES = {
    "NOP":       "0000",
    "ADD":       "0001",
    "SUB":       "0010",
    "MUL":       "0011",
    "DIV":       "0100",
    "MAC":       "0101",
    "MOV_ACC":   "0110",
    "CLR_ACC":   "0111",
    "AND":       "1000",
    "OR":        "1001",
    "XOR":       "1010",
    "NOT":       "1011",
    "SHL":       "1100",
    "SHR":       "1101",
    "LOAD_RAM":  "1110",
    "STORE_RAM": "1111",
}

REGS = {
    "R0": "00",
    "R1": "01",
    "R2": "10",
    "R3": "11",
}

def encode(op, r1, r2):
    return OPCODES[op] + REGS[r1] + REGS[r2]

def generate_program(L):
    prog = []
    X_START = 0
    Y_START = L
    H_START = 2 * L
    CONST_TABLE_START = 3 * L

    # Compute h[0] = y[0] / x[0]
    prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + Y_START}"))  # R0 = &y[0]
    prog.append(("LOAD_RAM", "R1", "R0"))                              # R1 = y[0]
    prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + X_START}"))  # R0 = &x[0]
    prog.append(("LOAD_RAM", "R2", "R0"))                              # R2 = x[0]
    prog.append(("DIV", "R3", "R2"))                                   # R3 = y[0]/x[0]
    prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + H_START}"))  # R0 = &h[0]
    prog.append(("STORE_RAM", "R0", "R3"))                             # store h[0]

    # For n = 1 .. L-1
    for n in range(1, L):
        prog.append(("CLR_ACC", "R0", "R0"))
        # Accumulate sum_{k=1}^{n} x[k] * h[n-k]
        for k in range(1, n+1):
            prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + X_START + k}"))  # &x[k]
            prog.append(("LOAD_RAM", "R1", "R0"))                                 # x[k]
            prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + H_START + (n - k)}")) # &h[n-k]
            prog.append(("LOAD_RAM", "R2", "R0"))                                 # h[n-k]
            prog.append(("MAC", "R1", "R2"))                                     # acc += x[k]*h[n-k]
        prog.append(("MOV_ACC", "R2", "R0"))                                     # R2 = sum
        prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + Y_START + n}"))    # &y[n]
        prog.append(("LOAD_RAM", "R1", "R0"))                                    # R1 = y[n]
        prog.append(("SUB", "R1", "R2"))                                         # R1 = y[n] - sum
        prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + X_START}"))        # &x[0]
        prog.append(("LOAD_RAM", "R2", "R0"))                                    # R2 = x[0]
        prog.append(("DIV", "R1", "R2"))                                         # R1 = h[n]
        prog.append(("LOAD_RAM", "R0", f"{CONST_TABLE_START + H_START + n}"))    # &h[n]
        prog.append(("STORE_RAM", "R0", "R1"))                                   # store h[n]

    # Add 2 NOPs at the end
    prog.append(("NOP", "R0", "R0"))
    prog.append(("NOP", "R0", "R0"))

    return prog

def generate_memory_init(L, x, y, expected_h):
    # Build memory image:
    # Addresses 0..L-1: x[n]
    # L..2L-1: y[n]
    # 2L..3L-1: h[n] (initially zero)
    # 3L..4L-1: constant table: addresses of x[0..L-1], y[0..L-1], h[0..L-1]
    X_START = 0
    Y_START = L
    H_START = 2 * L
    CONST_TABLE_START = 3 * L

    mem = [0] * (4 * L)  # total 4L bytes
    # fill x
    for i in range(L):
        mem[X_START + i] = x[i]
    # fill y
    for i in range(L):
        mem[Y_START + i] = y[i]
    # h initially zeros (already)
    # constant table: first L entries: addresses of x[0..L-1]
    for i in range(L):
        mem[CONST_TABLE_START + i] = X_START + i
    # next L entries: addresses of y[0..L-1]
    for i in range(L):
        mem[CONST_TABLE_START + L + i] = Y_START + i
    # last L entries: addresses of h[0..L-1]
    for i in range(L):
        mem[CONST_TABLE_START + 2*L + i] = H_START + i

    # Write hex file
    with open("ram_mem.hex", "w") as f:
        for byte in mem:
            f.write(f"{byte:02x}\n")

def main():
    L = 10
    # test data: impulse x, then y = x convolved with expected h
    x = [0] * L
    x[0] = 1
    # expected h: a 3-tap impulse response: h[0]=1, h[1]=1, h[2]=1, others 0
    expected_h = [0] * L
    expected_h[0] = 1
    expected_h[1] = 1
    expected_h[2] = 1
    # compute y = x * h (convolution)
    y = [0] * L
    for n in range(L):
        for k in range(max(0, n-L+1), min(n, L-1)+1):
            y[n] += x[k] * expected_h[n - k] if n-k < L else 0
    # generate program
    prog = generate_program(L)
    with open("program.asm", "w") as f:
        for (op, r1, r2) in prog:
            binary = encode(op, r1, r2)
            f.write(binary + "\n")
    # generate memory init file
    generate_memory_init(L, x, y, expected_h)
    print(f"Generated {len(prog)} instructions for L={L}")
    print("Memory init file 'ram_mem.hex' created.")

if __name__ == "__main__":
    main()

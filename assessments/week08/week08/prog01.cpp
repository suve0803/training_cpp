#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>


class Memory {
public:
    Memory() {
        memory.resize(65536, 0);
    }

    int read(int address) {
        return memory[address];
    }

    void write(int address, int value) {
        memory[address] = value;
    }

    void printSnapshot() {
        for (int i = 0; i < 16; i++) {
            std::cout << i << " -> " << memory[i] << std::endl;
        }
    }

private:
    std::vector<int> memory;
};
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isNum(const std::string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (!isDigit(str[i])) return false;
    }

    return true;
}

class Registers {
public:
    Registers() {
        registers["AX"] = 0;
        registers["BX"] = 0;
        registers["CX"] = 0;
        registers["DX"] = 0;
    }

    int get(const std::string& reg) {
        return registers[reg];
    }

    void set(const std::string& reg, int value) {
        registers[reg] = value;
    }

    void printSnapshot() {
        std::cout << "snapshot if the processor" << std::endl;
        std::cout << "AX: " << registers["AX"] << std::endl;
        std::cout << "BX: " << registers["BX"] << std::endl;
        std::cout << "CX: " << registers["CX"] << std::endl;
        std::cout << "DX: " << registers["DX"] << std::endl;
    }

private:
    std::unordered_map<std::string, int> registers;
};

class Processor {
public:
    Processor() : pc(0), run(true) {}

    void load_inst(const std::vector<std::string>& instructions) {
        this->instructions = instructions;
    }

    void execute(Memory& memory, Registers& registers) {
        while (run && pc < instructions.size()) {
            std::string instruction = instructions[pc];
            Execute(instruction, memory, registers);
            pc++;
        }
    }

    void PrintSnapshot(Memory& memory, Registers& registers) {
        std::cout << "Received Interrupt" << std::endl;
        registers.printSnapshot();
        memory.printSnapshot();
    }

private:
    int pc;
    bool run;
    std::vector<std::string> instructions;

    void Execute(const std::string& instruction, Memory& memory, Registers& registers) {
        size_t spacePosition = instruction.find(' ');
        std::string op;
        std::string args;

        if (spacePosition == std::string::npos) {
            op = instruction;
        }
        else {
            op = instruction.substr(0, spacePosition);
            args = instruction.substr(spacePosition + 1);
        }

        if (op == "MOV") {
            MOV(args, memory, registers);
        }
        else if (op == "ADD") {
            ADD(args, registers);
        }
        else if (op == "SUB") {
            SUB(args, registers);
        }
        else if (op == "MUL") {
            MUL(args, registers);
        }
        else if (op == "DIV") {
            DIV(args, registers);
        }
        else if (op == "HLT") {
            run = false;
        }
    }

    void MOV(const std::string& args, Memory& mem, Registers& reg) {
        size_t spacePosition = args.find(' ');
        std::string dest = args.substr(0, spacePosition);
        std::string src = args.substr(spacePosition + 1);

        if (src[0] == '[' && src[src.size() - 1] == ']') {
            int address = std::stoi(src.substr(1, src.size() - 2));
            int value = mem.read(address);

            if (dest[0] == '[' && dest[dest.size() - 1] == ']') {
                int destAddr = std::stoi(dest.substr(1, dest.size() - 2));
                mem.write(destAddr, value);
            }
            else {
                reg.set(dest, value);
            }
        }

        else if (isNum(src)) {
            int value = std::stoi(src);

            if (dest[0] == '[' && dest[dest.size() - 1] == ']') {
                int destAddr = std::stoi(dest.substr(1, dest.size() - 2));
                mem.write(destAddr, value);
            }
            else {
                reg.set(dest, value);
            }
        }
 
        else {
            int value = reg.get(src);

            if (dest[0] == '[' && dest[dest.size() - 1] == ']') {
                int destAddr = std::stoi(dest.substr(1, dest.size() - 2));
                mem.write(destAddr, value);
            }
            else {
                reg.set(dest, value);
            }
        }
    }

    void ADD(const std::string& args, Registers& reg) {
        size_t spacePosition = args.find(' ');
        std::string dest = args.substr(0, spacePosition);
        std::string src = args.substr(spacePosition + 1);

        int value;
        if (isNum(src)) {
            value = std::stoi(src);
        }
        else {
            value = reg.get(src);
        }

        int result = reg.get(dest) + value;
        reg.set("AX", result);
    }

    void SUB(const std::string& args, Registers& reg) {
        size_t spacePosition = args.find(' ');
        std::string dest = args.substr(0, spacePosition);
        std::string src = args.substr(spacePosition + 1);

        int value;
        if (isNum(src)) {
            value = std::stoi(src);
        }
        else {
            value = reg.get(src);
        }

        int result = reg.get(dest) - value;
        reg.set("AX", result);
    }

    void MUL(const std::string& args, Registers& reg) {
        size_t spacePosition = args.find(' ');
        std::string dest = args.substr(0, spacePosition);
        std::string src = args.substr(spacePosition + 1);

        int value;
        if (isNum(src)) {
            value = std::stoi(src);
        }
        else {
            value = reg.get(src);
        }

        int result = reg.get(dest) * value;
        reg.set("AX", result);
    }

    void DIV(const std::string& args, Registers& registers) {
        std::string dest = args;
        int div = registers.get(dest);
        if (div != 0) {
            int result = registers.get("AX") / div;
            registers.set("AX", result);
        }
        else {
            std::cerr << "Division by zero error" << std::endl;
        }
    }
};

int main() {
    Memory mem;
    Registers reg;
    Processor pro;

    std::ifstream infile("instructions.txt");
    std::vector<std::string> instructions;
    std::string line;

    while (std::getline(infile, line)) {
        instructions.push_back(line);
        if (line == "HLT") break;
    }

    pro.load_inst(instructions);
    pro.execute(mem, reg);
    pro.PrintSnapshot(mem, reg);

    return 0;
}


/*
 Received Interrupt
snapshot if the processor
AX: 0
BX: 0
CX: 0
DX: 0
0 -> 0
1 -> 0
2 -> 0
3 -> 0
4 -> 0
5 -> 0
6 -> 0
7 -> 0
8 -> 0
9 -> 0
10 -> 0
11 -> 0
12 -> 0
13 -> 0
14 -> 0
15 -> 0
*/
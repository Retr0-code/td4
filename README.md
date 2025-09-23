# TD4 Compiler

A compiler for TD4 4-bit processor instructions into its opcodes
with ability to extend and compile its assembly language to native CPU assembly.

You can use close to real TD4 emulator [td4dbg](https://github.com/Retr0-code/td4dbg) to debug your program.

## Compiler modules

`td4c` looks up for modules in `/usr/share/td4c` first and if not found in `./modules`.
These modules contain `td4::Compiler GetCompiler(void)` function, that should **not** be used directly, but within `td4::ArchitectureSelector` object.

## Building

To build CMake with Ninja is required. Preset debug compiles the debugger with no optimizations and include debug symbols. Preset release enables compiler optimizations.

# Rogue 5.4 - Windows Build Instructions

## Prerequisites

1. **Visual Studio 2022** (or Community/Enterprise)
   - Ensure C++ development tools are installed
   - MSVC compiler and build tools

## Project Setup

### 2. Project File Updates
Both project files have been updated to reference the `.cpp` files:
- `rogue54.vcxproj` - Updated all `<ClCompile Include="*.c" />` to `<ClCompile Include="*.cpp" />`

### 4. Curses Library Stubs
Created `stubs/curses.h` to provide Windows-compatible curses function stubs, including:
- Basic curses functions (`move`, `addch`, `refresh`, etc.)
- Missing functions found during compilation (`mvinch`, `clrtoeol`, `printw`, etc.)
- Type definitions (`chtype`, `WINDOW`)
- Constants (`A_CHARTEXT`)

## Building the Project

### Method 1: Using Visual Studio IDE
1. Open `rogue54.sln` in Visual Studio 2022
2. Select Debug configuration and Win32 platform
3. Build → Build Solution (Ctrl+Shift+B)

### Method 2: Using MSBuild from PowerShell
```powershell
# Navigate to project directory
cd "rogue5.4"

# Build using MSBuild
& MSBuild.exe rogue54.sln /p:Configuration=Debug /p:Platform=Win32
```

### Method 3: Using Developer Command Prompt
1. Open "Developer Command Prompt for VS 2022"
2. Navigate to project directory
3. Run: `msbuild rogue54.sln /p:Configuration=Debug /p:Platform=Win32`

## Remaining Issues

The following compilation errors may still need to be addressed:

1. **Type Safety Issues** - C++ requires explicit casts from `void*`
2. **Function Signature Mismatches** - Some function calls may need parameter adjustments
3. **Missing Dependencies** - Some curses functions may need full implementations
4. **Header Dependencies** - Missing `term.h` and other system headers

## File Structure
```
rogue5.4/
├── *.cpp                 # Renamed source files
├── *.h                   # Header files
├── rogue54.sln           # Visual Studio solution
├── rogue54.vcxproj       # Visual Studio project (newer format)
├── rogue54.vcproj        # Visual Studio project (legacy format)
├── stubs/
│   └── curses.h          # Windows curses compatibility layer
├── .vscode/
│   └── settings.json     # VS Code configuration (simplified)
└── instructions.md       # This file
```

## Build Tools Used

- **Compiler**: Microsoft Visual C++ 2022 (MSVC 14.44)
- **Build System**: MSBuild 17.14
- **IDE**: Visual Studio 2022 Professional
- **Platform**: Windows 10/11, x86 (Win32)

## Notes

- The original Linux Makefile remains unchanged for cross-platform compatibility
- Curses stubs provide minimal implementation for Windows compilation
- TRUE/FALSE constants are defined in rogue.h/extern.h, not in curses stubs
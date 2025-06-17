# EZres - Screen Resolution and Scaling Management Tool

English | [中文](README.md)

A lightweight command-line tool for quickly changing Windows screen resolution and DPI scaling.

## Features

- Quick screen resolution changes
- Set refresh rate (optional)
- Adjust DPI scaling percentage
- View current display settings
- List all available resolutions
- Immediate effect (for resolution)

## Command Line Options

| Option | Description | Example |
|--------|-------------|---------|
| `-r <width> <height> [refresh]` | Set screen resolution | `EZres.exe -r 1920 1080 60` |
| `-s <percentage>` | Set DPI scaling (100-500%) | `EZres.exe -s 125` |
| `-l` | Display current settings | `EZres.exe -l` |
| `-a` | List all available resolutions | `EZres.exe -a` |
| `-h` | Show help information | `EZres.exe -h` |

## Build Requirements

- C++17 compiler
- CMake 3.16+
- Windows API support

## Build Instructions

```bash
mkdir build ; cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

## Notes

- Administrator privileges may be required for certain system changes
- DPI scaling changes require logout/login to take full effect
- It's recommended to backup current settings before making changes
- Resolution changes take effect immediately

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for details.

### GPL v3 Key Terms:
- ✅ Free to use, modify, and distribute
- ✅ Commercial use allowed
- ❗ Modified versions must also be open source
- ❗ Must retain original copyright notices
- ❗ Must provide source code

## Contributing

Issues and Pull Requests are welcome!

If you want to contribute code, please ensure:
1. Comply with GPL v3 license
2. Add appropriate copyright notices
3. Maintain consistent coding style

## Copyright

Copyright (C) 2024 [Your Name]

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.


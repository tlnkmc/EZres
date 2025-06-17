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

## Usage

```bash
# Set resolution
EZres.exe -r 1920 1080
EZres.exe -r 1920 1080 60    # Specify refresh rate

# Set DPI scaling
EZres.exe -s 125             # 125% scaling

# View current settings
EZres.exe -l

# List available resolutions
EZres.exe -a

# Show help
EZres.exe -h
```

## Command Line Options

| Option | Description | Example |
|--------|-------------|---------|
| `-r <width> <height> [refresh]` | Set screen resolution | `EZres.exe -r 1920 1080 60` |
| `-s <percentage>` | Set DPI scaling (100-500%) | `EZres.exe -s 125` |
| `-l` | Display current settings | `EZres.exe -l` |
| `-a` | List all available resolutions | `EZres.exe -a` |
| `-h` | Show help information | `EZres.exe -h` |

## Notes

- Administrator privileges may be required for certain system changes
- DPI scaling changes require logout/login to take full effect
- It's recommended to backup current settings before making changes
- Resolution changes take effect immediately

## Troubleshooting

- **Missing compiler**: Install MinGW-w64 or Visual Studio
- **Permission denied**: Run as administrator
- **DPI not changing**: Logout and login again

## License

This project is open source. Feel free to use and modify.

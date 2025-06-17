# EZres - 屏幕分辨率和缩放管理工具

一个轻量级的命令行工具，用于快速更改Windows系统的屏幕分辨率和DPI缩放比例。

## 功能特性

- 快速更改屏幕分辨率
- 设置刷新率（可选）
- 调整DPI缩放比例
- 查看当前显示设置
- 列出所有可用分辨率
- 立即生效（分辨率）

## 编译要求

- C++17编译器
- CMake 3.16+
- Windows API支持

## 构建方法

```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

## 使用方法

```bash
# 设置分辨率
EZres.exe -r 1920 1080
EZres.exe -r 1920 1080 60    # 指定刷新率

# 设置DPI缩放
EZres.exe -s 125             # 125%缩放

# 查看当前设置
EZres.exe -l

# 列出可用分辨率
EZres.exe -a

# 显示帮助
EZres.exe -h
```

## 注意事项

- 需要管理员权限来修改某些系统设置
- DPI缩放更改需要注销重新登录才能完全生效
- 建议在更改前备份当前设置

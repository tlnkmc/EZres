#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

class DisplayManager {
private:
    static bool SetDPIScaling(int percentage) {
        HKEY hKey;
        LONG result = RegOpenKeyExW(HKEY_CURRENT_USER, 
            L"Control Panel\\Desktop", 0, KEY_SET_VALUE, &hKey);
        
        if (result != ERROR_SUCCESS) {
            return false;
        }

        // 计算DPI值 (96 DPI = 100%)
        int dpiValue = (96 * percentage) / 100;
        std::wstring dpiStr = std::to_wstring(dpiValue);
        
        result = RegSetValueExW(hKey, L"LogPixels", 0, REG_DWORD, 
            (BYTE*)&dpiValue, sizeof(dpiValue));
        
        RegCloseKey(hKey);
        
        if (result == ERROR_SUCCESS) {
            // 通知系统DPI已更改
            SendMessageW(HWND_BROADCAST, WM_SETTINGCHANGE, 
                SPI_SETLOGICALDPIOVERRIDE, 0);
            return true;
        }
        return false;
    }

public:
    static bool ChangeResolution(int width, int height, int refreshRate = 0) {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
            return false;
        }
        
        devMode.dmPelsWidth = width;
        devMode.dmPelsHeight = height;
        devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
        
        if (refreshRate > 0) {
            devMode.dmDisplayFrequency = refreshRate;
            devMode.dmFields |= DM_DISPLAYFREQUENCY;
        }
        
        LONG result = ChangeDisplaySettings(&devMode, CDS_UPDATEREGISTRY);
        return (result == DISP_CHANGE_SUCCESSFUL);
    }
    
    static bool SetScaling(int percentage) {
        if (percentage < 100 || percentage > 500) {
            std::cout << "缩放比例必须在100%-500%之间" << std::endl;
            return false;
        }
        
        return SetDPIScaling(percentage);
    }
    
    static void ListCurrentSettings() {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
            std::cout << "当前分辨率: " << devMode.dmPelsWidth 
                      << "x" << devMode.dmPelsHeight;
            if (devMode.dmDisplayFrequency > 0) {
                std::cout << " @" << devMode.dmDisplayFrequency << "Hz";
            }
            std::cout << std::endl;
        }
    }
    
    static void ListAvailableResolutions() {
        std::cout << "可用分辨率:" << std::endl;
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        for (int i = 0; EnumDisplaySettings(NULL, i, &devMode); i++) {
            std::cout << devMode.dmPelsWidth << "x" << devMode.dmPelsHeight;
            if (devMode.dmDisplayFrequency > 0) {
                std::cout << " @" << devMode.dmDisplayFrequency << "Hz";
            }
            std::cout << std::endl;
        }
    }
};

void ShowUsage() {
    std::cout << "用法:" << std::endl;
    std::cout << "  EZres.exe -r <宽度> <高度> [刷新率]  - 设置分辨率" << std::endl;
    std::cout << "  EZres.exe -s <百分比>              - 设置缩放比例 (100-500)" << std::endl;
    std::cout << "  EZres.exe -l                       - 显示当前设置" << std::endl;
    std::cout << "  EZres.exe -a                       - 显示所有可用分辨率" << std::endl;
    std::cout << "  EZres.exe -h                       - 显示帮助" << std::endl;
    std::cout << std::endl;
    std::cout << "示例:" << std::endl;
    std::cout << "  EZres.exe -r 1920 1080             - 设置为1920x1080" << std::endl;
    std::cout << "  EZres.exe -r 1920 1080 60          - 设置为1920x1080@60Hz" << std::endl;
    std::cout << "  EZres.exe -s 125                   - 设置缩放为125%" << std::endl;
}

int main(int argc, char* argv[]) {
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    if (argc < 2) {
        ShowUsage();
        return 1;
    }
    
    std::string command = argv[1];
    
    if (command == "-h" || command == "--help") {
        ShowUsage();
        return 0;
    }
    else if (command == "-l") {
        DisplayManager::ListCurrentSettings();
        return 0;
    }
    else if (command == "-a") {
        DisplayManager::ListAvailableResolutions();
        return 0;
    }
    else if (command == "-r" && argc >= 4) {
        int width = std::stoi(argv[2]);
        int height = std::stoi(argv[3]);
        int refreshRate = (argc >= 5) ? std::stoi(argv[4]) : 0;
        
        std::cout << "正在设置分辨率为 " << width << "x" << height;
        if (refreshRate > 0) {
            std::cout << "@" << refreshRate << "Hz";
        }
        std::cout << "..." << std::endl;
        
        if (DisplayManager::ChangeResolution(width, height, refreshRate)) {
            std::cout << "分辨率设置成功！" << std::endl;
            return 0;
        } else {
            std::cout << "分辨率设置失败！" << std::endl;
            return 1;
        }
    }
    else if (command == "-s" && argc >= 3) {
        int percentage = std::stoi(argv[2]);
        
        std::cout << "正在设置缩放比例为 " << percentage << "%..." << std::endl;
        
        if (DisplayManager::SetScaling(percentage)) {
            std::cout << "缩放比例设置成功！请注销并重新登录以完全生效。" << std::endl;
            return 0;
        } else {
            std::cout << "缩放比例设置失败！" << std::endl;
            return 1;
        }
    }
    else {
        std::cout << "无效的命令行参数！" << std::endl;
        ShowUsage();
        return 1;
    }
}

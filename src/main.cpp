#include <raylib.h>
#include <csignal>
#include <stdlib.h>

import config;
import renderer;
import device_manager;

Renderer* renderer = nullptr;
DeviceManager* device_manager = nullptr;

void signal_callback_handler(int signum)
{
    switch (signum)
    {
    case SIGTERM:
        TraceLog(LOG_INFO, "Interrupt signal received");
        break;
    
    case SIGABRT:
        /* code */
        break;

    default:
        break;
    }
    exit(signum);
}

int main(int argc, char** argv)
{
    std::signal(SIGTERM, signal_callback_handler);
    std::signal(SIGABRT, signal_callback_handler);

    auto config = LoadConfig();

    renderer = new Renderer();
    renderer->Init(config);

    device_manager = new DeviceManager();
    device_manager->PowerSw(); // Starting up

    while (!WindowShouldClose())    //当用户关闭窗口或者按下ESC键时返回true，否则返回false
    {
        //更新和计算相关状态变量
        renderer->Draw();
    }
    CloseWindow();

    return 0;
}
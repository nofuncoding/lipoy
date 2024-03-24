module;

#include <raylib.h>

module renderer;

void Renderer::Init(Config config)
{
    // 初始化渲染器
    InitWindow(config.screen_width, config.screen_height, "Lipoy");
    SetTargetFPS(config.fps);
}

void Renderer::Draw()
{
    // 渲染场景
    BeginDrawing(); //准备进行帧的绘制
    ClearBackground(BLACK); //清除之前帧绘制的内容
    //绘制一帧
    EndDrawing(); //完成帧的绘制，并根据设置的帧率延时（自动暂停一段时间，以满足帧率要求）。
}
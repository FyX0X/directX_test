#include "Engine.h"


bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	if (!this->render_window.Initialize(this, hInstance, window_title, window_class, width, height))
	{
		return false;
	}
	if (!gfx.Initialize(this->render_window.GetHWND(), width, height))
	{
		return false;
	}
	//keyboard.EnableAutoRepeatChars();
	//keyboard.EnableAutoRepeatKeyss();
	return true; 
}

bool Engine::ProcessMessages()
{
	return this->render_window.ProcessMessages();
}

void Engine::Update()
{
	while (!keyboard.CharBufferIsEmpty())
	{
		unsigned char c = keyboard.ReadChar();

	}
	while (!keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent ke = keyboard.ReadKey();
		unsigned char keycode = ke.getKeyCode();

	}
	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();
	}
}

void Engine::RenderFrame()
{
	gfx.RenderFrame();
}

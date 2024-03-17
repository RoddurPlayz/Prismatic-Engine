#pragma once


#include <iostream>
#include <sstream>
#include <vector>
#include <source_location>

#define GLEW_STATIC
#include "../GL/glew.h"
#include "../GLFW/glfw3.h"

#include "__macros.h"
#include "__error.h"


PRISMmonitor* prismGetPrimaryMonitor();
const PRISMvidmode* prismGetVideoMode(PRISMmonitor *monitor);


class PrismWindow
{
private:
	GLFWwindow* m_Window;
	int m_Width;
	int m_Height;
	int m_Xpos;
	int m_Ypos;
	std::string m_Title;

	bool m_IsFullscreen;
	bool m_IsResizable;
	int m_VsyncMode;
	
	bool m_IsDestroyed;
	bool m_ShouldWindowClose;
public:
	PrismWindow();
	PrismWindow(
		int width, int height,
		std::string title = "Prismatic",
		PRISMmonitor* monitor = nullptr, PrismWindow* share = nullptr,
		std::source_location location = std::source_location::current()
	);

	void GLFWHint(int hint, int value);

	bool IsActive();
	void MakeActive();

	const unsigned char* GetOpenGLVersion();

	bool ShouldClose();
	void SetShouldClose(bool value);

	bool IsDestroyed();
	void Destroy();

	void SetSizeLimit(int minwidth = -1, int minheight = -1, int maxwidth = -1, int maxheight = -1);
	
	int GetWidth();
	int GetHeight();
	void SetSize(int width, int height);

	bool IsFullscreen();
	void SetFullscreen(bool value, PRISMmonitor* monitor = prismGetPrimaryMonitor());

	bool IsResizable();
	void SetResizable(bool value);

	int GetXPosition();
	int GetYPosition();
	void SetPosition(int x, int y);

	std::string GetTitle();
	void SetTitle(std::string title);

	int GetVsyncMode();
	void SetVsyncMode(int value = -1);

	void Fill(int red, int green, int blue, int alpha, std::source_location location = std::source_location::current());

	void Update();

	bool GetEventState(PRISMevent EventType);
};


PrismWindow& prismCreateWindow(
	int width, int height,
	std::string title = "Prismatic",
	PRISMmonitor* monitor = nullptr, PrismWindow* share = nullptr,
	std::source_location location = std::source_location::current()
);


static inline PrismWindow* __ActiveWindow = nullptr;
static inline std::vector<PrismWindow> __Windows;


PrismWindow& prismGetActiveWindow();
std::vector<PrismWindow>& prismGetWindows();

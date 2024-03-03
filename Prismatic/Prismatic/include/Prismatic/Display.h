#pragma once


#include <iostream>
#include <vector>
#include <source_location>

#include "../GL/glew.h"
#include "../GLFW/glfw3.h"

#include "Error.h"


#define PRISMmonitor GLFWmonitor
#define PRISMvidmode GLFWvidmode

#define PRISMkeycallbackfunction GLFWkeyfun


PRISMmonitor* prismGetPrimaryMonitor();
const PRISMvidmode* prismGetVideoMode(PRISMmonitor *monitor);


class PRISMwindow
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

	bool m_ShouldWindowClose;
public:
	PRISMwindow(int width, int height, std::string title = "Prismatic", PRISMmonitor* monitor = nullptr, PRISMwindow* share = nullptr, std::source_location location = std::source_location::current());

	bool IsActive();
	void MakeActive();

	bool ShouldClose();
	// TODO: Fix this function which takes in a function pointer and arguments of the function to call it
	template <typename Function, typename... Arguments>
	bool ShouldClose(Function function, Arguments... arguments);
	void SetShouldClose(bool value);

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

	void Fill(int red, int green, int blue, int alpha);

	void Update();

	void SetKeyCallback(PRISMkeycallbackfunction function);
};


static inline PRISMwindow* __ActiveWindow = nullptr;
static inline std::vector<PRISMwindow> __Windows;


PRISMwindow& prismGetActiveWindow();
std::vector<PRISMwindow>& prismGetWindows();

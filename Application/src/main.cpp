#include <iostream>

#include <prismatic.h>


void Win1(PRISMwindow& window)
{
	window.MakeActive();

	window.Fill(0, 0, 255, 255);

	window.Update();
}

void Win2(PRISMwindow& window)
{
	window.MakeActive();

	window.Fill(255, 0, 255, 255);

	window.Update();
}


int main()
{
	prismInit();

	PRISMwindow window1{ 800, 600 };
	PRISMwindow window2{ 800, 600 };

	while (!window1.ShouldClose() && !window2.ShouldClose())
	{
		prismProcessEvents();

		Win1(window1);
		Win2(window2);
	}

	prismQuit();

	return 0;
}

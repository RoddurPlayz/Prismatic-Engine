#pragma once


#include "__display.h"


class PrismScene
{
private:
	PrismWindow* m_Window;
protected:
	PrismWindow window;

	virtual void events();
	virtual void render();
	virtual void update();
public:
	PrismScene();
	PrismScene(PrismWindow& window);

	void MakeTargetWindow(PrismWindow& window);

	void run();
};

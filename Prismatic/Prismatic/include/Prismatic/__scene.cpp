#include "__scene.h"


PrismScene::PrismScene()
	:m_Window(nullptr),
	window(*m_Window)
{ }

PrismScene::PrismScene(PrismWindow& window)
	:m_Window(&window),
	window(window)
{ }

void PrismScene::MakeTargetWindow(PrismWindow& window)
{
	m_Window = &window;
	this->window = *m_Window;
}

void PrismScene::events() { }

void PrismScene::render() { }

void PrismScene::update() { }

void PrismScene::run()
{
	if (!window.ShouldClose())
	{
		window.MakeActive();

		events();
		render();
		update();

		window.Update();
	}
}

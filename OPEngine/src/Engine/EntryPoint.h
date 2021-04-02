#pragma once

#ifdef OPE_PLATFORM_WINDOWS

extern OPEngine::Application* OPEngine::CreateApplication();

int main(int argc, char **argv)
{

	auto app = OPEngine::CreateApplication();
	app->Update();
	delete app;

	return 1;
}

#endif
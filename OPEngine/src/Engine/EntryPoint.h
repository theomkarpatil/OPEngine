#pragma once


#ifdef OPE_PLATFORM_WINDOWS

extern OPEngine::Application* OPEngine::CreateApplication();

int main(int argc, char **argv)
{
	OPEngine::Log::Init();
	
	OPE_ENGINE_INFO("OP Engine Initialized");
	OPE_ENGINE_WARNING("Something little is wrong");
	OPE_ENGINE_ERROR("Something BIG is wrong");

	auto app = OPEngine::CreateApplication();
	app->Update();
	delete app; 

	return 1;
}

#endif
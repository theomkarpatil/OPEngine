#include "Sandbox.h"

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

OPEngine::Application* OPEngine::CreateApplication()
{
	return new Sandbox();
}


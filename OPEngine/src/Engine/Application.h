#pragma once

#include "macros.h"

namespace OPEngine {

class OPE_API Application{
	public:
		Application();
		virtual ~Application();

		void Update();
	};

Application* CreateApplication();
}


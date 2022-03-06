#pragma once

#include "ApplicationWindow.h"
#include "Caption.h"

namespace Subtend
{
    class Application
    {
    public:
        Application();

        void Update();

    private:
        SharedPtr<CaptionManager> m_CaptionManager;
        ApplicationWindow m_Window;
    };
}

#pragma once

#include "GUI/CaptionPane.h"

namespace Subtend
{
    class ApplicationWindow
    {
    public:
        ApplicationWindow(SharedPtr<CaptionManager> cm);

        void RenderUI();

    private:

        CaptionPane m_CaptionPane;
    };
}

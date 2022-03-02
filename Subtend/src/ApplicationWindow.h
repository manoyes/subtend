#pragma once

#include "GUI/CaptionPane.h"

namespace Subtend
{
    class ApplicationWindow
    {
    public:
        ApplicationWindow();

        void RenderUI();

    private:

        CaptionPane m_CaptionPane;
    };
}

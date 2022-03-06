#pragma once

#include "Model/Caption.h"

namespace Subtend
{
    class CaptionPane
    {
    public:
        CaptionPane(SharedPtr<CaptionManager> cm);

        void RenderUI();

    private:

        void DrawCaption(std::list<Caption>::iterator& caption, int index);

       SharedPtr<CaptionManager> m_Context;
    };
}


#pragma once

#include "Model/Caption.h"

namespace Subtend 
{
    class HistogramPane
    {
    public:
        HistogramPane(SharedPtr<CaptionManager> cm);

        void RenderUI();
    private:

        void DrawCaption(std::list<Caption>::iterator& caption, int index);
        void DrawHistogram();

        SharedPtr<CaptionManager> m_Context;
    };
}

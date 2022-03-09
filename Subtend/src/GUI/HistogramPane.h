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

        void DrawControls();
        void DrawCaptions();
        void DrawPlot();
        void DrawMultiPlot();

        SharedPtr<CaptionManager> m_Context;
    };
}

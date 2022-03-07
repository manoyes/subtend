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

        void DrawCaptions();
        void DrawPlot();
        void DrawMultiPlot();
        void DrawControls();

        SharedPtr<CaptionManager> m_Context;
    };
}

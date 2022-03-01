#include "sbtpch.h"
#include "CaptionPane.h"

#include "imgui.h"

namespace Subtend
{

    void Subtend::CaptionPane::RenderUI()
    {
        ImGui::Begin("Caption Editor");
        ImGui::Button("Hello");
        static float value = 0.0f;
        ImGui::DragFloat("Value", &value);
        ImGui::End();
    }

}

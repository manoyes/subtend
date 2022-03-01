#include "sbtpch.h"
#include "CaptionPane.h"

#include "imgui.h"

namespace Subtend
{

    void Subtend::CaptionPane::RenderUI()
    {
        ImGui::Begin("Caption Editor");

        // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
        // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
        static char subtitle[50 * 2] =
            " In the name of the father, and of the son, \n"
            " En el nombre del padre, del hijo,\n";
        static char starttime[12] = "00:00:00000";
        static char endtime[12] = "00:01:00000";

        static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput | ImGuiInputTextFlags_CtrlEnterForNewLine;
        ImGui::InputTextMultiline("##subtitle", subtitle, IM_ARRAYSIZE(subtitle), ImVec2(ImGui::GetTextLineHeight() * 30, ImGui::GetTextLineHeight() * 3), flags);

        ImGui::SameLine();

        ImGui::Button("X", ImVec2(32, ImGui::GetTextLineHeight() * 3));

        ImGui::SameLine();

        ImGui::BeginGroup();
        ImGui::InputText("##starttime", starttime, IM_ARRAYSIZE(starttime), flags);
        ImGui::InputText("##endtime", endtime, IM_ARRAYSIZE(endtime), flags);
        ImGui::EndGroup();

        ImGui::Button("+", ImVec2(24,24));

        ImGui::End();
    }

}

#include "sbtpch.h"
#include "GUI/CaptionPane.h"

#include "imgui.h"

namespace Subtend
{
    CaptionPane::CaptionPane(SharedPtr<CaptionManager> cm)
        : m_Context(cm)
    {
    }

    void Subtend::CaptionPane::RenderUI()
    {
        ImGui::Begin("Caption Editor");
        unsigned int i = 0;

        for (std::list<Caption>::iterator it = m_Context->Begin(); it != m_Context->End(); it++)
        {
            DrawCaption(it, i);
            i++;
            if (it == m_Context->End()) break;
        }

        ImGui::End();
    }

    void CaptionPane::DrawCaption(std::list<Caption>::iterator& it, int index)
    {
        Caption& caption = *it;

        bool needsDeletion = false;

        // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
        // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
        char subtitle[256];
        char starttime[12];
        char endtime[12];

        memset(subtitle, 0, sizeof(subtitle));
        memset(starttime, 0, sizeof(starttime));
        memset(endtime, 0, sizeof(endtime));

        std::strncpy(subtitle, caption.Subtitle.c_str(), sizeof(subtitle));
        std::strncpy(starttime, caption.StartTime.c_str(), sizeof(starttime));
        std::strncpy(endtime, caption.EndTime.c_str(), sizeof(endtime));

        static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput | ImGuiInputTextFlags_CtrlEnterForNewLine;
        if (ImGui::InputTextMultiline(std::string("##subtitle" + std::to_string(index)).c_str(), subtitle, IM_ARRAYSIZE(subtitle), ImVec2(ImGui::GetTextLineHeight() * 30, ImGui::GetTextLineHeight() * 3), flags))
        {
            caption.Subtitle = std::string(subtitle);
        }

        ImGui::SameLine();

        ImGui::PushID(std::string("##X" + std::to_string(index)).c_str());
        if (ImGui::Button("X", ImVec2(32, ImGui::GetTextLineHeight() * 3)))
        {
            needsDeletion = true;
        }
        ImGui::PopID();

        ImGui::SameLine();

        ImGui::BeginGroup();
        if (ImGui::InputText(std::string("##starttime" + std::to_string(index)).c_str(), starttime, IM_ARRAYSIZE(starttime), flags))
        {
            caption.StartTime = std::string(starttime);
        }

        if (ImGui::InputText(std::string("##endtime" + std::to_string(index)).c_str(), endtime, IM_ARRAYSIZE(endtime), flags))
        {
            caption.EndTime = std::string(endtime);
        }

        ImGui::EndGroup();

        ImGui::PushID(std::string("##+" + std::to_string(index)).c_str());
        if (ImGui::Button("+", ImVec2(24, 24)))
        {
            if (it != m_Context->End())
            {
                it++;
                m_Context->Insert(it, { "New Subtitle", caption.EndTime, caption.EndTime });
                it--;
            }
            else
            {
                m_Context->PushBack({ "New Subtitle", caption.EndTime, caption.EndTime });
            }
        }
        ImGui::PopID();

        if (needsDeletion && m_Context->Size() > 1)
        {
            it = m_Context->Erase(it);
        }
    }

}

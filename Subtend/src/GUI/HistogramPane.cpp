#include "sbtpch.h"
#include "GUI/HistogramPane.h"

#include "imgui.h"


Subtend::HistogramPane::HistogramPane(SharedPtr<CaptionManager> cm)
    : m_Context(cm)
{
}

void Subtend::HistogramPane::RenderUI()
{
    ImGui::Begin("Histogram Editor");
    unsigned int i = 0;

    for (std::list<Caption>::iterator it = m_Context->Begin(); it != m_Context->End(); it++)
    {
        DrawCaption(it, i);
        i++;
        if (it == m_Context->End()) break;
    }

    DrawHistogram();

    ImGui::End();
}

void Subtend::HistogramPane::DrawCaption(std::list<Caption>::iterator& caption, int index)
{
    
}

void Subtend::HistogramPane::DrawHistogram()
{
    static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };

    // By default, if we don't enable ScrollX the sizing policy for each columns is "Stretch"
// Each columns maintain a sizing weight, and they will occupy all available width.
    static ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchSame | ImGuiTableFlags_Resizable | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_ContextMenuInBody;

    if (ImGui::BeginTable("CaptionTable", m_Context->Size(), flags))
    {
       ImGui::TableNextRow();

       
       unsigned int column = 0;

       for (std::list<Caption>::iterator it = m_Context->Begin(); it != m_Context->End(); it++, column++)
       {
            ImGui::TableSetColumnIndex(column);
            ImGui::Text(it->Subtitle.c_str(), column, 0);
       }
        ImGui::EndTable();
    }


    ImGui::PlotHistogram("", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));
}

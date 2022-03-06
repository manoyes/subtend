#include "sbtpch.h"
#include "GUI/HistogramPane.h"

#include "imgui.h"
#include "imgui_plot.h"

namespace Subtend
{
    constexpr size_t buf_size = 44100 * 180;
    static float x_data[buf_size];
    static float y_data1[buf_size];
    static float y_data2[buf_size];
    static float y_data3[buf_size];

    HistogramPane::HistogramPane(SharedPtr<CaptionManager> cm)
        : m_Context(cm)
    {
        constexpr float sampling_freq = 44100;
        constexpr float freq = 500;
        for (size_t i = 0; i < buf_size; ++i) {
            const float t = i / sampling_freq;
            x_data[i] = t;
            const float arg = 2 * 3.14159 * freq * t;
            y_data1[i] = sin(arg);
            y_data2[i] = y_data1[i] * -0.6 + sin(2 * arg) * 0.4;
            y_data3[i] = y_data2[i] * -0.6 + sin(3 * arg) * 0.4;
        }
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
        DrawPlot();
    
        ImGui::End();
    }
    
    void HistogramPane::DrawCaption(std::list<Caption>::iterator& caption, int index)
    {
        
    }
    
    void HistogramPane::DrawHistogram()
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
    
    void HistogramPane::DrawPlot()
    {
        //ImGui::PlotConfig conf;
        //static float y_data[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
    
        ////conf.values.xs = x_data; // this line is optional
        //conf.values.ys = y_data;
        //conf.values.count = 7;
        //conf.scale.min = -1;
        //conf.scale.max = 1;
        //conf.tooltip.show = true;
        //conf.tooltip.format = "x=%.2f, y=%.2f";
        //conf.grid_x.show = true;
        //conf.grid_y.show = true;
        //conf.frame_size = ImVec2(400, 400);
        //conf.line_thickness = 2.f;
    
        //ImGui::Plot("plot", conf);

        DrawMultiPlot();
    }
    
    void HistogramPane::DrawMultiPlot() {
        static const float* y_data[] = { y_data1, y_data2, y_data3 };
        static ImU32 colors[3] = { ImColor(0, 255, 0), ImColor(255, 0, 0), ImColor(0, 0, 255) };
        static uint32_t selection_start = 0, selection_length = 0;
    
        //ImGui::Begin("Example plot", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        // Draw first plot with multiple sources
        ImGui::PlotConfig conf;
        conf.values.xs = x_data;
        conf.values.count = buf_size;
        conf.values.ys_list = y_data; // use ys_list to draw several lines simultaneously
        conf.values.ys_count = 1;
        conf.values.colors = colors;
        conf.scale.min = -1;
        conf.scale.max = 1;
        conf.tooltip.show = true;
        conf.grid_x.show = true;
        conf.grid_x.size = 44100 * 10;
        conf.grid_x.subticks = 4;
        conf.grid_y.show = true;
        conf.grid_y.size = 0.5f;
        conf.grid_y.subticks = 5;
        conf.selection.show = true;
        conf.selection.start = &selection_start;
        conf.selection.length = &selection_length;
        //conf.frame_size = ImVec2(buf_size, 200);
        conf.frame_size = ImVec2(2560, 200);
        ImGui::Plot("plot1", conf);
    
        // Draw second plot with the selection
        // reset previous values
        conf.values.ys_list = nullptr;
        conf.selection.show = false;
        // set new ones
        conf.values.ys = y_data3;
        conf.values.offset = selection_start;
        conf.values.count = selection_length;
        conf.line_thickness = 2.f;
        ImGui::Plot("plot2", conf);
    
        //ImGui::End();
    }
}

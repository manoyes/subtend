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
        
        DrawControls();
        DrawCaptions();
        DrawPlot();
    
        ImGui::End();
    }
    

    void HistogramPane::DrawControls()
    {
        // Replace with current video timestamp
        ImGui::Text("0:00:00");
        ImGui::SameLine();
        ImGui::Button("Undo");
        ImGui::SameLine();
        ImGui::Button("Redo");
        ImGui::SameLine();

        static float zoomValue;
        ImGui::SliderFloat("Zoom", &zoomValue, 0, 1);
    }
    void HistogramPane::DrawCaptions()
    {
        float totalColumnWidth = 0.0f;
        std::vector<float> columnWidths;
        float currentColumnWidth = 0.0f;

        static float videoLengthInSeconds = 180.0f;

        unsigned int n = 0;

        ImGui::BeginTable("Caption Timeline", m_Context->Size(), ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders);

        for (std::list<Caption>::iterator it = m_Context->Begin(); it != m_Context->End(); it++, n++)
        {
            ImGui::TableNextColumn();

            columnWidths.push_back(ImGui::GetColumnWidth(ImGui::GetColumnIndex()));
            totalColumnWidth += columnWidths.back();

            ImGui::PushID(std::string("##subtitle" + std::to_string(n)).c_str());
            ImGui::Selectable(it->Subtitle.c_str(), &it->Selected, ImGuiSelectableFlags_None);
            ImGui::PopID();

            // Our buttons are both drag sources and drag targets here!
            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
            {
                // Set payload to carry the index of our item (could be anything)
                ImGui::SetDragDropPayload("HISTOGRAM_CAPTION", &it, sizeof(std::list<Caption>::iterator));

                // Display preview (could be anything, e.g. when dragging an image we could decide to display
                // the filename and a small preview of the image, etc.)
                ImGui::Text((it->Subtitle).c_str());

                ImGui::EndDragDropSource();
            }
            if (ImGui::BeginDragDropTarget())
            {
                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("HISTOGRAM_CAPTION"))
                {
                    IM_ASSERT(payload->DataSize == sizeof(std::list<Caption>::iterator));
                    std::list<Caption>::iterator payload_it = *(std::list<Caption>::iterator*)payload->Data;

                    m_Context->Insert(it, *payload_it);
                    m_Context->Erase(payload_it);
                }
                ImGui::EndDragDropTarget();
            }

            if (std::next(it) != m_Context->End())
                ImGui::SameLine();
        }
        ImGui::EndTable();

        unsigned int i = 0;
        float accumulated_width = 0.0f;

        for (std::list<Caption>::iterator it = m_Context->Begin(); it != m_Context->End(); it++, accumulated_width += columnWidths[i++])
        {
            float start = (accumulated_width / totalColumnWidth) * videoLengthInSeconds;
            float end = ((accumulated_width + columnWidths[i]) / totalColumnWidth) * videoLengthInSeconds;

            int startMilliseconds = start * 1000;
            int startSeconds = start;
            int startMinutes = startSeconds / 60;
            int startHours = startMinutes / 60;

            int endMilliseconds = end * 1000;
            int endSeconds = end;
            int endMinutes = endSeconds / 60;
            int endHours = endMinutes / 60;

            std::stringstream ss;
            std::stringstream es;

            ss << startHours % 60 << ":" << startMinutes % 60 << ":" << startSeconds % 60 << "," << startMilliseconds % 1000;
            es << endHours % 60 << ":" << endMinutes % 60 << ":" << endSeconds % 60 << "," << endMilliseconds % 1000;

            it->StartTime = ss.str();
            it->EndTime = es.str();
        }
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
        conf.frame_size = ImVec2(1920, 64);
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

#pragma once

#include <list>

namespace Subtend
{
    struct Caption
    {
        std::string Subtitle;
        std::string StartTime;
        std::string EndTime;

        bool operator==(const Caption& rhs) const
        {
            return
                Subtitle == rhs.Subtitle &&
                StartTime == rhs.StartTime &&
                EndTime == rhs.EndTime;
        }
    };

    class CaptionPane
    {
    public:
        CaptionPane() = default;

        void RenderUI();

        void AddCaption(std::string subtitle, std::string starttime, std::string endtime);
        void RemoveCaption(std::string subtitle, std::string starttime, std::string endtime);

    private:

        void DrawCaption(std::list<Caption>::iterator& caption, int index);

        std::list<Caption> m_Captions;
    };
}


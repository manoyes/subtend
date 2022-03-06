#pragma once

#include <list>

namespace Subtend
{
    struct Caption
    {
        std::string Subtitle;
        std::string StartTime;
        std::string EndTime;

        Caption(std::initializer_list<std::string> l)
        {
            std::initializer_list<std::string>::iterator it = l.begin();
            Subtitle = *it++;
            StartTime = *it++;
            EndTime = *it++;
        }

        bool operator==(const Caption& rhs) const
        {
            return
                Subtitle == rhs.Subtitle &&
                StartTime == rhs.StartTime &&
                EndTime == rhs.EndTime;
        }
    };

    class CaptionManager : std::list<Caption>
    {

    public:
        CaptionManager() = default;

        void AddCaption(std::string subtitle, std::string starttime, std::string endtime);
        void RemoveCaption(std::string subtitle, std::string starttime, std::string endtime);
        std::list<Caption>::iterator Begin();
        std::list<Caption>::iterator End();
        void PushBack(std::initializer_list<std::string> c);
        void Insert(std::list<Caption>::iterator it, Caption c);
        size_t Size() const;
        std::list<Caption>::iterator Erase(std::list<Caption>::iterator it);
    };
}

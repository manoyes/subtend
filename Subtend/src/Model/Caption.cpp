#include "sbtpch.h"
#include "Caption.h"

namespace Subtend
{
    void CaptionManager::AddCaption(std::string subtitle, std::string starttime, std::string endtime)
    {
        push_back({ subtitle, starttime, endtime });
    }

    void CaptionManager::RemoveCaption(std::string subtitle, std::string starttime, std::string endtime)
    {
        remove({ subtitle, starttime, endtime });
    }

    std::list<Caption>::iterator CaptionManager::Begin()
    {
        return begin();
    }

    std::list<Caption>::iterator CaptionManager::End()
    {
        return end();
    }

    void CaptionManager::PushBack(std::initializer_list<std::string> c)
    {
        push_back(c);
    }

    void CaptionManager::Insert(std::list<Caption>::iterator it, Caption c)
    {
        insert(it, c);
    }

    size_t CaptionManager::Size() const
    {
        return size();
    }

    std::list<Caption>::iterator CaptionManager::Erase(std::list<Caption>::iterator it)
    {
       return erase(it);
    }
}

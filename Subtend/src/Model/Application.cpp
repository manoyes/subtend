#include "sbtpch.h"
#include "Application.h"

namespace Subtend
{
    Subtend::Application::Application()
        : m_CaptionManager(MakeSharedPtr<CaptionManager>())
        , m_Window(m_CaptionManager)
    {
        m_CaptionManager->AddCaption("Hello world", "00:00:00000", "00:01:00000");
    }
    
    void Subtend::Application::Update()
    {
        m_Window.RenderUI();
    }
}

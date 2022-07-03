#include "EditorWindowsManager.h"
#include "EditorWindowsManager.h"
#include "SceneWindow.h"
#include "ProjectWindow.h"
#include "PropertiesWindow.h"
#include "ConsoleWindow.h"
#include "OutlinerWindow.h"
#include "OutputWindow.h"
#include "MainMenuBarWindow.h"
#include "DockspaceWindow.h"
namespace SapphireEditor
{
    void EditorWindowManager::Reset()
    {
        this->windows.push_back(msptr(new DockspaceWindow));
        this->windows.push_back(msptr(new SceneWindow));
        this->windows.push_back(msptr(new ProjectWindow));
        this->windows.push_back(msptr(new PropertiesWindow));
        this->windows.push_back(msptr(new ConsoleWindow));
        this->windows.push_back(msptr(new OutlinerWindow));
        this->windows.push_back(msptr(new OutputWindow));
        this->windows.push_back(msptr(new MainMenuBarWindow));

        for (auto window : this->windows)
        {
            window->set_is_opened(true);
        }
    }
    void EditorWindowManager::Draw()
    {
        for (const auto& window : windows)
        {
            if (!window->get_is_opened())
            {
                continue;
            }
            window->DrawImGui();
        }
    }
}
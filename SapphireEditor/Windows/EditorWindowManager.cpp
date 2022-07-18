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
        this->windows.push_back(mksptr(new DockspaceWindow));
        this->windows.push_back(mksptr(new MainMenuBarWindow));
        this->windows.push_back(mksptr(new ProjectWindow));
        this->windows.push_back(mksptr(new PropertiesWindow));
        this->windows.push_back(mksptr(new ConsoleWindow));
        this->windows.push_back(mksptr(new OutlinerWindow));
        this->windows.push_back(mksptr(new SceneWindow));
        this->windows.push_back(mksptr(new OutputWindow));

        for (auto window : this->windows)
        {
            window->Open();
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
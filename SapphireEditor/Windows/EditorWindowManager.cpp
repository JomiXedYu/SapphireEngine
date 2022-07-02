#include "EditorWindowsManager.h"
#include "SceneWindow.h"
#include "ProjectWindow.h"
#include "PropertiesWindow.h"
#include "ConsoleWindow.h"
#include "OutlinerWindow.h"

namespace SapphireEditor
{
    void EditorWindowManager::Reset()
    {
        this->windows.push_back(msptr(new SceneWindow));
        this->windows.push_back(msptr(new ProjectWindow));
        this->windows.push_back(msptr(new PropertiesWindow));
        this->windows.push_back(msptr(new ConsoleWindow));
        this->windows.push_back(msptr(new OutlinerWindow));
    }
}
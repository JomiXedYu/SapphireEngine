#pragma once

#include <SapphireEditor/Editor.h>
#include <vector>
#include "EditorWindow.h"

namespace SapphireEditor
{
    class EditorWindowManager
    {
    public:
        static EditorWindowManager* GetInstance()
        {
            static EditorWindowManager* instance = new EditorWindowManager;
            return instance;
        }

        std::vector<sptr<EditorWindow>> windows;

        void Reset();
    };
}

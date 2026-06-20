#pragma once

#include <core/modules/ModuleManager.h>

namespace nova::core
{

class CoreApplication
{
public:

    bool initialize();

    void run();

    void shutdown();

private:

    ModuleManager m_moduleManager;
};

}
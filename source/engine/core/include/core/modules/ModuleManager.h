#pragma once

#include <core/modules/IModule.h>

#include <memory>
#include <vector>

namespace nova::core
{

class ModuleManager
{
public:


ModuleManager() = default;

~ModuleManager();

bool registerModule(std::unique_ptr<IModule> module);

bool initializeModules();

void shutdownModules();


private:


std::vector<std::unique_ptr<IModule>> m_modules;


};

}

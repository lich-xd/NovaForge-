#include <core/modules/ModuleManager.h>

namespace nova::core
{

ModuleManager::~ModuleManager()
{
shutdownModules();
}

bool ModuleManager::registerModule(std::unique_ptr<IModule> module)
{
if (!module)
return false;

m_modules.push_back(std::move(module));

return true;

}

bool ModuleManager::initializeModules()
{
for (auto& module : m_modules)
{
if (!module->initialize())
return false;
}


return true;


}

void ModuleManager::shutdownModules()
{
for (auto it = m_modules.rbegin();
it != m_modules.rend();
++it)
{
(*it)->shutdown();
}
}

}

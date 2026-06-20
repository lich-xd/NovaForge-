#include <core/application/CoreApplication.h>

#include <iostream>

namespace nova::core
{

bool CoreApplication::initialize()
{
std::cout << "[NovaForge] Initialize\n";


return m_moduleManager.initializeModules();


}

void CoreApplication::run()
{
std::cout << "[NovaForge] Run\n";
}

void CoreApplication::shutdown()
{
std::cout << "[NovaForge] Shutdown\n";


m_moduleManager.shutdownModules();


}

}

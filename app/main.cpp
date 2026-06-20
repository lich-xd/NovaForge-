#include <core/application/CoreApplication.h>

int main()
{
nova::core::CoreApplication app;

if (!app.initialize())
    return -1;

app.run();

app.shutdown();

return 0;


}

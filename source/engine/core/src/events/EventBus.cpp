#include <core/events/EventBus.h>

namespace nova::core
{

std::unordered_map
<
    std::type_index,
    std::vector<EventBus::InternalHandler>
>
EventBus::s_handlers;

std::mutex EventBus::s_mutex;

}
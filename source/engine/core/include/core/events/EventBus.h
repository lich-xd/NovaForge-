#pragma once

#include <core/events/Event.h>

#include <functional>
#include <mutex>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace nova::core
{

class EventBus
{
public:

    template<typename EventType>
    using Handler = std::function<void(const EventType&)>;

    template<typename EventType>
    static void subscribe(Handler<EventType> handler)
    {
        std::lock_guard lock(s_mutex);

        auto wrapper =
            [handler](const Event& event)
            {
                handler(
                    static_cast<const EventType&>(event));
            };

        s_handlers[typeid(EventType)]
            .push_back(wrapper);
    }

    template<typename EventType>
    static void publish(const EventType& event)
    {
        std::lock_guard lock(s_mutex);

        auto it =
            s_handlers.find(typeid(EventType));

        if (it == s_handlers.end())
            return;

        for (auto& handler : it->second)
        {
            handler(event);
        }
    }

private:

    using InternalHandler =
        std::function<void(const Event&)>;

    static std::unordered_map
    <
        std::type_index,
        std::vector<InternalHandler>
    > s_handlers;

    static std::mutex s_mutex;
};

}
// We'll use a string and the gzmsg command below for a brief example.
// Remove these includes if your plugin doesn't need them.
#include <string>
#include <gz/common/Console.hh>

// This header is required to register plugins. It's good practice to place it
// in the cc file, like it's done here.
#include <gz/plugin/Register.hh>

// Don't forget to include the plugin's header.
#include "ack_gazebo/FullSystem.hh"

// This is required to register the plugin. Make sure the interfaces match
// what's in the header.
IGNITION_ADD_PLUGIN(
    ack_gazebo::FullSystem,
    gz::sim::System,
    ack_gazebo::FullSystem::ISystemConfigure,
    ack_gazebo::FullSystem::ISystemPreUpdate,
    ack_gazebo::FullSystem::ISystemUpdate,
    ack_gazebo::FullSystem::ISystemPostUpdate
)

namespace ack_gazebo 
{

void FullSystem::Configure(const gz::sim::Entity &_entity,
                const std::shared_ptr<const sdf::Element> &_element,
                gz::sim::EntityComponentManager &_ecm,
                gz::sim::EventManager &_eventManager)
{
  igndbg << "ack_gazebo::FullSystem::Configure on entity: " << _entity << std::endl;
}

void FullSystem::PreUpdate(const gz::sim::UpdateInfo &_info,
                           gz::sim::EntityComponentManager &_ecm)
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ack_gazebo::FullSystem::PreUpdate" << std::endl;
  }
}

void FullSystem::Update(const gz::sim::UpdateInfo &_info,
                        gz::sim::EntityComponentManager &_ecm)
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ack_gazebo::FullSystem::Update" << std::endl;
  }
}

void FullSystem::PostUpdate(const gz::sim::UpdateInfo &_info,
                            const gz::sim::EntityComponentManager &_ecm) 
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ack_gazebo::FullSystem::PostUpdate" << std::endl;
  }
}

}  // namespace ack_gazebo
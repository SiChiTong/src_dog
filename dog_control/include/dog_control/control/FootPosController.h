#ifndef DOG_CONTROL_CONTROL_FOOTPOSCONTROLLER_H
#define DOG_CONTROL_CONTROL_FOOTPOSCONTROLLER_H

#include "dog_control/hardware/HardwareBase.h"
#include "dog_control/physics/DogPhysics.h"
#include "dog_control/message/FootState.h"
#include "dog_control/utils/Initializer.h"

#include <array>
#include <boost/weak_ptr.hpp>

namespace dog_control
{

namespace control
{

class FootPosController
{
protected:
    using FootState = message::FootState;
    using FootConfiguration = message::FootConfiguration;
    using FootStateCRef = message::FootStateCRef;
    using FootConfigCRef = message::FootConfigCRef;

public:
    FootPosController();

    void Initialize(utils::ParamDictCRef dict);

    void ConnectHardware(boost::shared_ptr<hardware::HardwareBase> hw);
    void ConnectPhysics(boost::shared_ptr<physics::DogPhysics> phys);

    void ChangeFootControlMethod(FootConfigCRef config);

    void SetFootState(FootStateCRef foot_state);

    FootState GetFootState(message::LegName foot_name) const;

    void Update();

private:
    boost::weak_ptr<physics::DogPhysics> phys_ptr_;
    boost::weak_ptr<hardware::HardwareBase> hw_ptr_;

    std::array<FootState, 4> cmd_footstate_;
    std::array<FootState, 4> real_footstate_;

    std::array<FootConfiguration, 4> config_;
};

} /* control */

} /* dog_control */

#endif /* DOG_CONTROL_CONTROL_FOOTPOSCONTROLLER_H */
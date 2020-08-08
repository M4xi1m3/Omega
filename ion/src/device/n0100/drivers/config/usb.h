#ifndef ION_DEVICE_N0100_CONFIG_USB_H
#define ION_DEVICE_N0100_CONFIG_USB_H

#include <regs/regs.h>

namespace Ion {
namespace Device {
namespace USB {
namespace Config {

using namespace Regs;

constexpr static AFGPIOPin VbusPin(GPIOA, 9, GPIO::AFR::AlternateFunction::AF10, GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::Fast);
constexpr static AFGPIOPin DmPin(GPIOA, 11, GPIO::AFR::AlternateFunction::AF10, GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::Fast);
constexpr static AFGPIOPin DpPin(GPIOA, 12, GPIO::AFR::AlternateFunction::AF10, GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::Fast);

#if EXTERNAL_FLASH_8M
constexpr static const char * InterfaceStringDescriptor = "@Flash/0x08000000/04*016Kg,01*064Kg,07*128Kg/0x90000000/08*004Kg,01*032Kg,63*064Kg,64*064Kg";
#elif EXTERNAL_FLASH_16M
constexpr static const char * InterfaceStringDescriptor = "@Flash/0x08000000/04*016Kg,01*064Kg,07*128Kg/0x90000000/08*004Kg,01*032Kg,63*064Kg,64*064Kg,128*064Kg";
#else
constexpr static const char * InterfaceStringDescriptor = "@Flash/0x08000000/04*016Kg,01*064Kg,07*128Kg";
#endif

}
}
}
}

#endif

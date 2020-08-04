#ifndef ION_DEVICE_N0100_CONFIG_EXTERNAL_FLASH_H
#define ION_DEVICE_N0100_CONFIG_EXTERNAL_FLASH_H

#include <regs/regs.h>
#include <drivers/config/clocks.h>

/*  Pin | Role                 | Mode                  | Function
 * -----+----------------------+-----------------------+-----------------
 *  PB2 | QUADSPI CLK          | Alternate Function  9 | QUADSPI_CLK
 *  PB6 | QUADSPI BK1_NCS      | Alternate Function 10 | QUADSPI_BK1_NCS
 *  PC8 | QUADSPI BK1_IO2/WP   | Alternate Function  9 | QUADSPI_BK1_IO2
 *  PC9 | QUADSPI BK1_IO0/SO   | Alternate Function  9 | QUADSPI_BK1_IO0
 * PD12 | QUADSPI BK1_IO1/SI   | Alternate Function  9 | QUADSPI_BK1_IO1
 * PD13 | QUADSPI BK1_IO3/HOLD | Alternate Function  9 | QUADSPI_BK1_IO3
 */

namespace Ion {
namespace Device {
namespace ExternalFlash {
namespace Config {

using namespace Regs;

#if EXTERNAL_FLASH_8M
constexpr static uint32_t StartAddress = 0x90000000;
constexpr static uint32_t EndAddress = 0x90800000;

constexpr static int NumberOf4KSectors = 8;
constexpr static int NumberOf32KSectors = 1;
constexpr static int NumberOf64KSectors = 128 - 1;

constexpr static AFGPIOPin Pins[] = {
  AFGPIOPin(GPIOB, 2,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOB, 6,  GPIO::AFR::AlternateFunction::AF10, GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOC, 8,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOC, 9,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOD, 12, GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOD, 13, GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
};

#elif EXTERNAL_FLASH_16M
constexpr static uint32_t StartAddress = 0x90000000;
constexpr static uint32_t EndAddress = 0x91000000;

constexpr static int NumberOf4KSectors = 8;
constexpr static int NumberOf32KSectors = 1;
constexpr static int NumberOf64KSectors = 256 - 1;

constexpr static AFGPIOPin Pins[] = {
  AFGPIOPin(GPIOB, 2,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOB, 6,  GPIO::AFR::AlternateFunction::AF10, GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOC, 8,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOC, 9,  GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOD, 12, GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
  AFGPIOPin(GPIOD, 13, GPIO::AFR::AlternateFunction::AF9,  GPIO::PUPDR::Pull::None, GPIO::OSPEEDR::OutputSpeed::High),
};

#else
constexpr static uint32_t StartAddress = 0xFFFFFFFF;
constexpr static uint32_t EndAddress = 0xFFFFFFFF;

constexpr static int NumberOf4KSectors = 0;
constexpr static int NumberOf32KSectors = 0;
constexpr static int NumberOf64KSectors = 0;
constexpr static AFGPIOPin Pins[] = {};
#endif

constexpr static int NumberOfSectors = NumberOf4KSectors + NumberOf32KSectors + NumberOf64KSectors;
constexpr static int ClockFrequencyDivisor = Clocks::Config::AHBFrequency / 96 * 2;

}
}
}
}

#endif

/**
 * (c) Copyright 2017  Florian Müller (contact@petrockblock.com)
 * https://github.com/petrockblog/ControlBlock2
 *
 * Permission to use, copy, modify and distribute the program in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * This program is freeware for PERSONAL USE only. Commercial users must
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for the program or software derived from the program.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so everyone can benefit from the modifications
 * in future versions.
 */

#ifndef CONTROLBLOCK_H
#define CONTROLBLOCK_H

#include <stdint.h>
#include <iostream>

#include "PowerSwitch.h"
#include "gamepads/InputDevice.h"
#include "config/ISingleConfiguration.h"
#include "uinput/IUInputFactory.h"
#include "hal/IDigitalIn.h"
#include "hal/IDigitalOut.h"

class ControlBlock
{
public:
    ControlBlock(IUInputFactory& uiFactoryRef, IDigitalIn& digitalInRef, IDigitalOut& digitalOutRef);
    ~ControlBlock();

    ControlBlock(const ControlBlock& other) = delete;
    ControlBlock& operator=(const ControlBlock&) = delete;

    void update();

private:
    static const uint8_t MAX_NUMBER_OF_CONTROLBLOCKS = 2u;

    uint8_t m_numberOfGamepads;

    PowerSwitch* powerSwitch;
    InputDevice* gamepads[MAX_NUMBER_OF_CONTROLBLOCKS];
    IUInputFactory* uiFactory;
    IDigitalIn* digitalIn;
    IDigitalOut* digitalOut;

    InputDevice::Channel_e getInputDevice(int counterValue);
    void createGamepad(ISingleConfiguration::GamepadType_e type, InputDevice*& device);

};

#endif // CONTROLBLOCK_H

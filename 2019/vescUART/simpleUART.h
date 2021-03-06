/*
Copyright 2015 - 2017 Andreas Chaitidis Andreas.Chaitidis@gmail.com

This program is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.

*/
#include "config.h"

#ifndef _VESCUART_h
#define _VESCUART_h

///PackSendPayload Packs the payload and sends it over Serial.
///Define in a Config.h a SERIAL with the Serial in Arduino Style you want to you
///@param: payload as the payload [unit8_t Array] with length of int lenPayload
///@return the number of bytes send
int PackSendPayload(uint8_t* payload, int lenPay);

///ReceiveUartMessage receives the a message over Serial
///Define in a Config.h a SERIAL with the Serial in Arduino Style you want to you
///@parm the payload as the payload [unit8_t Array]
///@return the number of bytes receeived within the payload
int ReceiveUartMessage(uint8_t* payloadReceived);

///Help Function to print struct bldcMeasure over Serial for Debug
///Define in a Config.h the DEBUGSERIAL you want to use
void SerialPrint(const struct bldcMeasure& values);

///Sends a command to VESC and stores the returned data
///@param bldcMeasure struct with received data
//@return true if sucess
bool VescUartGetValue(struct bldcMeasure& values);

#endif

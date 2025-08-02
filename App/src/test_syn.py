import asyncio
from bleak import BleakClient
import time
import fluidsynth
import struct


DEVICE_ADDRESS = "08:33:08:33:08:33"
READ_UUID = "0000fef4-0000-1000-8000-00805f9b34fb"

fs = fluidsynth.Synth()

note_map = {

    0x00000FFF: 85, # Do#
    0x00000DFF: 84, # Do
    0x000007FF: 83, # Si
    0x000003FF: 82, # Sib
    0x000005FF: 81, # La
    0x000001FF: 81, # La
    0x0000048F: 80, # Sol#
    0x0000008F: 80, # Sol#
    0x000004FF: 79, # Sol
    0x000000FF: 79, # Sol
    0x000000FF: 78, # Fa#
    0x000004FF: 78, # Fa#
    0x000000E7: 77, # Fa
    0x000004E7: 77, # Fa
    0x000000E7: 76, # Mi
    0x000004E7: 76, # Mi
    0x000000E1: 75, # Re#
    0x000004E1: 75, # Re#
    0x000000E3: 74, # Re
    0x000004E3: 74, # Re

    0x00001FFF: 73, # Do#
    0x00001DFF: 72, # Do
    0x000017FF: 71, # Si
    0x000013FF: 70, # Sib
    0x000015FF: 69, # La
    0x000011FF: 69, # La
    0x0000148F: 68, # Sol#
    0x0000108F: 68, # Sol#
    0x000014FF: 67, # Sol
    0x000010FF: 67, # Sol
    0x000010FF: 66, # Fa#
    0x000014FF: 66, # Fa#
    0x000010E7: 65, # Fa
    0x000014E7: 65, # Fa
    0x000010E7: 64, # Mi
    0x000014E7: 64, # Mi
    0x000010E1: 63, # Re#
    0x000014E1: 63, # Re#
    0x000010E3: 62, # Re
    0x000014E3: 62, # Re
    0x000010B2: 60, # Do#
    0x000014B2: 60, # Do#
    0x000010E2: 60, # Do
    0x000014E2: 60, # Do

}
current_note = 72

def play_note(data):
    global current_note

    values = struct.unpack('<II', data)
    #print(values)
    note = note_map.get(values[0], current_note)
    if note != current_note:
        fs.noteoff(0, current_note)
        fs.noteon(0, note, 127)
        current_note = note


async def main():

    fs.start()
    sfid = fs.sfload("SF2/Acordeon Amar Azul.sf2")
    fs.program_select(0, sfid, 0, 0)

    async with BleakClient(DEVICE_ADDRESS) as client:
        print("Client connected successfully")

        while 1:
            data = await client.read_gatt_char(READ_UUID)
            print(data)
            play_note(data)


asyncio.run(main())
fs.delete()



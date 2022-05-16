from PIL import Image
import struct

filename = input()
with open(filename, "rb") as f:
    resol  = struct.unpack("<QQ", f.read(16))
    img    = Image.new(mode="RGB", size=resol)
    pixels = img.load()

    for i in range(resol[0]):
        for j in range(resol[1]):
            pixels[i,j] = struct.unpack("<BBB", f.read(3))

    img.show()

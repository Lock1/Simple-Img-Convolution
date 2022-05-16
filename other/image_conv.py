from PIL import Image
import struct

src_name = input()
with Image.open(src_name) as f:
    with open(src_name[:len(src_name)-3] + "sis", "wb") as out:
        out.write(struct.pack("<QQ", f.width, f.height))
        pixels = f.load()
        for i in range(f.width):
            for j in range(f.height):
                px = pixels[i,j]
                out.write(struct.pack("<BBB", px[0], px[1], px[2]))

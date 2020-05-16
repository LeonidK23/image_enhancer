from PIL import Image
import numpy as np

import sys
import os

data = np.loadtxt(sys.argv[1])
im = Image.fromarray(data).convert("L")

pngFilePath = os.path.splitext(sys.argv[1])[0] + ".png"
im.save(pngFilePath)

from PIL import Image
import numpy as np

import sys
import os

img = Image.open(sys.argv[1])
im_arr = np.asarray(img.convert('L'))

txt_filename = os.path.splitext(sys.argv[1])[0] + ".txt"
np.savetxt(txt_filename, im_arr, fmt="%i")

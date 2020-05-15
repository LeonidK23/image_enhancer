from imageReader import imageReader
from filters.binaryFilter import binaryFilter
from filters.equalizeFilter import equalizeFilter
from filters.SauvolaFilter import SauvolaFilter

import matplotlib.pyplot as plt
import numpy as np
from timeit import default_timer as timer

filepath = '../data/page_photo.png'

reader = imageReader()
im_arr = reader.read(filepath, to_grayscale=True)
print(im_arr.shape)
# np.savetxt("../data/page_photo.txt", im_arr, fmt="%i")

sF = SauvolaFilter(window_size=15)

start = timer()
filtered_image = sF.filter(im_arr)
end = timer()
print(end - start)

reader.save(filtered_image, '../data/page_photo_sauvola.jpeg')

# filtered = np.loadtxt("../data/page_photo_filtered.txt")
# reader.save(filtered, '../data/page_photo_sauvola_c.jpeg')

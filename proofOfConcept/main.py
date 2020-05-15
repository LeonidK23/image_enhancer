from imageReader import imageReader
from filters.binaryFilter import binaryFilter
from filters.equalizeFilter import equalizeFilter
from filters.SauvolaFilter import SauvolaFilter

import matplotlib.pyplot as plt
import numpy as np

filepath = '../data/page_photo.png'

reader = imageReader()
im_arr = reader.read(filepath, to_grayscale=True)

sF = SauvolaFilter(window_size=10)

filtered_image = sF.filter(im_arr)

reader.save(filtered_image, '../data/page_photo_sauvola.jpeg')

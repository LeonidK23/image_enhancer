from imageReader import imageReader
from filters.binaryFilter import binaryFilter
from filters.equalizeFilter import equalizeFilter

import matplotlib.pyplot as plt
import numpy as np

filepath = '../data/page_photo.png'

reader = imageReader()
im_arr = reader.read(filepath, to_grayscale=True)

#plt.hist(im_arr.flatten(), bins=256)
#plt.show()

n_blocks_x = 10
m, n = im_arr.shape
n_blocks_y = 10
n_pixels_x = int(np.ceil(m/n_blocks_x))
n_pixels_y = int(np.ceil(n/n_blocks_y))
filtered_image = np.zeros_like(im_arr)
print(im_arr.shape)

eF = equalizeFilter()
# bF = binaryFilter(threshold='intermeans')
im_arr = eF.filter(im_arr)
window_size = 7
for i in range(window_size, m - window_size):
    for j in range(window_size, n - window_size):
        print(i - window_size, i + window_size, j - window_size, j + window_size)
        # filtered_arr = eF.filter(im_arr[i - window_size: i + window_size, j - window_size: j + window_size])
        window_arr = im_arr[i - window_size: i + window_size, j - window_size: j + window_size]
        mean = np.mean(window_arr)
        threshold = mean - 0.2*np.std(window_arr)
        # print(filtered_arr)
        window_arr = 255 * (window_arr > threshold)
        try:
            filtered_image[i, j] = window_arr[window_size, window_size]
        except:
            filtered_image[i, j] = 0
        # print(filtered_image.shape)

# for i in range(n_blocks_x):
#     for j in range(n_blocks_y):
#         ind_y1 = j*n_pixels_y
#         ind_y2 = (j + 1)*n_pixels_y
#         ind_x1 = i*n_pixels_x
#         ind_x2 = (i + 1)*n_pixels_x
#         print(ind_x1, ind_x2, ind_y1, ind_y2)
#         filtered_image[ind_x1: ind_x2, ind_y1: ind_y2] = eF.filter(im_arr[ind_x1: ind_x2, ind_y1: ind_y2])
        # filtered_image[ind_x1: ind_x2, ind_y1: ind_y2] = bF.filter(im_arr[ind_x1: ind_x2, ind_y1: ind_y2])

# filtered_image = bF.filter(im_arr)

# print(filtered_image)
# plt.hist(filtered_image.flatten(), bins=256)
# plt.show()

reader.save(filtered_image, '../data/page_photo_niblack.jpeg')

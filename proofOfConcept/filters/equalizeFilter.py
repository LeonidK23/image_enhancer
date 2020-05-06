import numpy as np
import scipy.stats as ss

from filters.imageFilter import ImageFilter

class equalizeFilter(ImageFilter):

    def filter(self, image_arr):
        m, n = image_arr.shape
        cdf_min = np.min(ss.rankdata(image_arr.flatten(), method='max'))

        new_arr = 255*(ss.rankdata(image_arr.flatten(), method='max') - cdf_min)/(m*n - cdf_min)

        return new_arr.reshape(m, n)

import numpy as np

from filters.imageFilter import ImageFilter

class SauvolaFilter(ImageFilter):

    def __init__(self, window_size):
        self.window_size = window_size

    def filter(self, image_arr):
        m, n = image_arr.shape
        filtered_image = np.zeros_like(image_arr)

        for i in range(self.window_size, m - self.window_size - 1):
            for j in range(self.window_size, n - self.window_size - 1):
                # print(i - window_size, i + window_size, j - window_size, j + window_size)
                window_arr = image_arr[i - self.window_size: i + self.window_size + 1, j - self.window_size: j + self.window_size + 1]
                mean = np.mean(window_arr)
                # niblack
                # threshold = mean - 0.1*np.std(window_arr)
                # sauvola
                threshold = mean*(1 - 0.1*(1 - np.std(window_arr)/128))
                # bernsen
                # threshold = 0.5*(np.max(window_arr) + np.min(window_arr))

                window_arr = 255 * (window_arr > threshold)
                try:
                    filtered_image[i, j] = window_arr[self.window_size, self.window_size]
                except:
                    filtered_image[i, j] = 0

        return filtered_image

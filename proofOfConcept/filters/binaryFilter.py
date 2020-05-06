import numpy as np
from sklearn.cluster import KMeans

from filters.imageFilter import ImageFilter

class binaryFilter(ImageFilter):

    def __init__(self, threshold='mean'):
        self.threshold = '_' + threshold

    def filter(self, image_arr):
        threshold = self.__compute_threshhold(self.threshold, image_arr)
        filtered_image = 255 * (image_arr > threshold)

        return filtered_image.astype(np.uint8)

    def __compute_threshhold(self, func, data):
        return getattr(self, func)(data)

    def _mean(self, data):
        return np.mean(data)

    def _median(self, data):
        return np.median(data)

    def _intermeans(self, data):
        kmeans = KMeans(n_clusters=2, random_state=0).fit(data.reshape(-1,1))

        return np.mean(kmeans.cluster_centers_)

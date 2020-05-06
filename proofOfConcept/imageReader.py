from PIL import Image
import numpy as np

class imageReader:
    def __init__(self):
        pass

    def read(self, filepath, to_grayscale=True):
        img = Image.open(filepath)
        if to_grayscale:
            data = np.asarray(img.convert('L'), dtype="int32")
        else:
            data = np.asarray(img, dtype="int32")

        return data

    def save(self, data, filepath):
        im = Image.fromarray(data).convert("L")
        im.save(filepath)

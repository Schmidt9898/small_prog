print("lession 6")

from PIL import Image, ImageFilter
#filename = "IMG/1.jpg"
#with Image.open(filename) as img:
#	img.load()
#print(img)

#print(img.size)
#imsize=(100,100,200,200)
#img=img.crop(imsize)
#img=img.convert("L")
#img=img.filter(ImageFilter.FIND_EDGES)
#img.show()

##

filename = "IMG/IMG3.png"
with Image.open(filename) as img:
	img.load()

#img.show()

img=img.crop((0,250,img.size[0],300))
print(img.size)
img=img.convert("L")
#img=img.filter(ImageFilter.SMOOTH)
#img=img.filter(ImageFilter.UnsharpMask(radius=3, percent=200, threshold=3))
img=img.point(lambda x: 255 if x> 180 else 0)
#img=img.filter(ImageFilter.SMOOTH)
img=img.filter(ImageFilter.SMOOTH)
#img.collapse
#img=img.filter(ImageFilter.)
xm,ym=img.size
print(xm,ym)
imcollapsed=[]
for x in range(xm):
	temp_sum=0
	for y in range(ym):
		temp_sum+=img.getpixel((x,y))
	imcollapsed.append(temp_sum/ym)
	
import numpy as np

#print(imcollapsed)
val=np.array(imcollapsed)
val=np.fft.rfft(val)

from scipy.signal import find_peaks

peeks=find_peaks(val, height=None, threshold=200, distance=None, prominence=None, width=None, wlen=None, rel_height=0.5, plateau_size=None)
print(peeks)

import matplotlib.pyplot as plt
plt.plot(val)
plt.show()
#print(val)


img.show()
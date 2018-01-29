from ctypes import *

cberry = CDLL('./cberry.so')

cberry.initScreen()
cberry.setPenColor(cberry.getColor("RED"))
cberry.drawCircle(100,100, 20)
cberry.closeScreen()

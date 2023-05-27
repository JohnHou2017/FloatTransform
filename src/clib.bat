del libNumber.lib
del *.o
g++ -c ByteOrder.c
g++ -c Float2SEF.c
g++ -c SEF2Byte.c
g++ -c Byte2SEF.c
g++ -c SEF2Float.c
g++ -c IeeeFloat.c
g++ -c IbmFloat.c
g++ -c VaxFloat.c
g++ -c TestlibNumber.c
ar m libNumber.lib
ar r libNumber.lib *.o
ar t libNumber.lib
del *.o

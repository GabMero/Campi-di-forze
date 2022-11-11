INCS:=`root-config --cflags`
LIBS:=`root-config --libs`

main: main.cpp CampoVettoriale.h Posizione.h Particella.h PuntoMateriale.h
	g++ main.cpp -o main ${INCS} ${LIBS}
clean:
	rm main
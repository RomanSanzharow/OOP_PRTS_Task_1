#ifndef PNI_TRAX_H//guard
#define PNI_TRAX_H

struct TraxD{
	float       kHeading;//компоненты
	float         kPitch;
	float          kRoll;
	 char kHeadingStatus;
	float kQuaternion[4];
	float   kTemperature;
	 bool    kDistortion;
	 bool     kCalStatus;
	float        kAccelX;
	float        kAccelY;
	float        kAccelZ;
	float          kMagX;
	float          kMagY;
	float          kMagZ;
	float         kGyroX;
	float         kGyroY;
	float         kGyroZ;//компоненты
};

class Trax{
public:
	Trax(unsigned char a[], const int b);//конструктор-разборщик посылки
	void TraxShow();//метод печати компонент
private:
	TraxD data;
	float ByteToFloat(unsigned char a[], int b);//преобразует 4 байта Big Endian во float
	bool ByteToBool(unsigned char a[], int b);//преобразует 1 байт Big Endian в bool
};

#endif//guard

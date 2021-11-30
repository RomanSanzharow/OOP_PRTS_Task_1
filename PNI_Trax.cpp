#include "PNI_Trax.h"
#include <iostream>

Trax::Trax(unsigned char a[], const int b){//конструктор-разборщик посылки
	      data.kHeading = 0.0;//начальное обнуление компонент
	        data.kPitch = 0.0;
	         data.kRoll = 0.0;
	data.kHeadingStatus = 'A';
	data.kQuaternion[0] = 0.0;
	data.kQuaternion[1] = 0.0;
	data.kQuaternion[2] = 0.0;
	data.kQuaternion[3] = 0.0;
	  data.kTemperature = 0.0;
	   data.kDistortion = false;
	    data.kCalStatus = false;
	       data.kAccelX = 0.0;
	       data.kAccelY = 0.0;
	       data.kAccelZ = 0.0;
	         data.kMagX = 0.0;
	         data.kMagY = 0.0;
             data.kMagZ = 0.0;
            data.kGyroX = 0.0;
	        data.kGyroY = 0.0;
	        data.kGyroZ = 0.0;//начальное обнуление компонент
	for (int i = 0; i < b;){
		int key = *reinterpret_cast<unsigned char*>(&a[i]);//читаем ключ (unsigned char -> int)
		i++;//"считывающая головка"
		switch (key){
		case 5: {
			data.kHeading = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				}
		case 24: {
			data.kPitch = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 25: {
			data.kRoll = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 79: {
			data.kHeadingStatus = a[i];
			i += sizeof(char);
			break;
				 }
		case 77: {
			data.kQuaternion[0] = ByteToFloat(a, i);
			i += sizeof(float);
			data.kQuaternion[1] = ByteToFloat(a, i);
			i += sizeof(float);
			data.kQuaternion[2] = ByteToFloat(a, i);
			i += sizeof(float);
			data.kQuaternion[3] = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 7: {
			data.kTemperature = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				}
		case 8: {
			data.kDistortion = ByteToBool(a, i);
			i += sizeof(bool);
			break;
				}
		case 9: {
			data.kCalStatus = ByteToBool(a, i);
			i += sizeof(bool);
			break;
				}
		case 21: {
			data.kAccelX = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 22: {
			data.kAccelY = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 23: {
			data.kAccelZ = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 27: {
			data.kMagX = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 28: {
			data.kMagY = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 29: {
			data.kMagZ = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 74: {
			data.kGyroX = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 75: {
			data.kGyroY = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		case 76: {
			data.kGyroZ = ByteToFloat(a, i);
			i += sizeof(float);
			break;
				 }
		default: {
			std::cerr << "Wrong ID-key" << std::endl;
			break;
				 }
		}
	}
}

void Trax::TraxShow(){
	std::cout << "kHeading = " << data.kHeading << std::endl;
	std::cout << "kPitch = " << data.kPitch << std::endl;
	std::cout << "kRoll  = " << data.kRoll  << std::endl;
	std::cout << "kHeadingStatus  = " << data.kHeadingStatus  << std::endl;
	std::cout << "kQuaternion = [" << data.kQuaternion[0] << "; "
								   << data.kQuaternion[1] << "; "
								   << data.kQuaternion[2] << "; "
								   << data.kQuaternion[3] << "]"
								   << std::endl;
	std::cout << "kTemperature = " << data.kTemperature<< std::endl;

	std::cout << "kDistortion= "; 
	if (data.kDistortion)
		std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "kCalStatus = ";
	if (data.kCalStatus)
		std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "kAccelX = " << data.kAccelX << std::endl;
	std::cout << "kAccelY = " << data.kAccelY << std::endl;
	std::cout << "kAccelZ = " << data.kAccelZ << std::endl;
	std::cout << "kMagX = " << data.kMagX << std::endl;
	std::cout << "kMagY = " << data.kMagY << std::endl;
	std::cout << "kMagZ = " << data.kMagZ << std::endl;
	std::cout << "kGyroX = " << data.kGyroX << std::endl;
	std::cout << "kGyroY = " << data.kGyroY << std::endl;
	std::cout << "kGyroZ = " << data.kGyroZ << std::endl;
}

float Trax::ByteToFloat(unsigned char a[], int b){//преобразует 4 байта Big Endian во float
	return *reinterpret_cast<float*>(&a[b]);
}

bool Trax::ByteToBool(unsigned char a[], int b){//преобразует 1 байт Big Endian во bool
	return *reinterpret_cast<bool*>(&a[b]);
}

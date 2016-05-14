#include <iostream.h>
#include <iomanip.h>
#include <jni.h>
//#include "Teste.h"
extern "C" JNIEXPORT void JNICALL Java_Teste_foo (JNIEnv *, jobject)
{
	printf("roda??\n");
	cout << "e esse?" << endl;
}


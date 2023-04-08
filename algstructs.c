#include "PIFF.h"
#include "struct.h"
#include "size.h"
#include <string.h>
#include <stdlib.h>

JNIEXPORT void JNICALL Java_PIFF_passToC(JNIEnv* env, jobject jobj, jobjectArray objarr)
{
	initSize = (*env)->GetArrayLength(env, objarr);
	arr = (struct PIFF*)malloc(initSize * sizeof(struct PIFF));
	for (int i = 0; i < initSize; i++)
	{
		jstring string = (jstring)((*env)->GetObjectArrayElement(env, objarr, i));
		const char* rawString = (*env)->GetStringUTFChars(env, string, 0);
		sscanf(rawString, "%s %d %d %d %d %d %d", arr[i].ID, &arr[i].x_low, &arr[i].x_high, &arr[i].y_low, &arr[i].y_high, &arr[i].z_low, &arr[i].z_high);
	}
}
#include "PIFF.h"
#include "struct.h"
#include "size.h"
#include <stdlib.h>

JNIEXPORT jobjectArray JNICALL Java_PIFF_algA(JNIEnv * env, jobject jobj)
{
	int totalSize = 0;
	for (int i = 0; i < initSize; i++)
		totalSize = totalSize + (arr[i].x_high - arr[i].x_low) * (arr[i].y_high - arr[i].y_low) * (arr[i].z_high - arr[i].z_low);

	jobjectArray result;
	result = (jobjectArray)(*env)->NewObjectArray(env, totalSize, (*env)->FindClass(env, "java/lang/String"), 0);
    char numBuff[4];
    int index = 0;

	for (int i = 0; i < initSize; i++)
	{
		char* temp = (char*)malloc(sizeof(arr[i].ID) + 25);
		for (int x = arr[i].x_low; x < arr[i].x_high; x++)
		{
			for (int y = arr[i].y_low; y < arr[i].y_high; y++)
			{
				for (int z = arr[i].z_low; z < arr[i].z_high; z++)
				{
					strcpy(temp, arr[i].ID);
					strcat(temp, " ");

					sprintf(numBuff, "%d", x);
					strcat(temp, numBuff);
					strcat(temp, " ");

					sprintf(numBuff, "%d", x+1);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", y);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", y+1);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", z);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", z+1);
                    strcat(temp, numBuff);

					(*env)->SetObjectArrayElement(env, result, index, (*env)->NewStringUTF(env, temp));
					index++;
				}
			}
		}
		free(temp);
	}
	return result;
}
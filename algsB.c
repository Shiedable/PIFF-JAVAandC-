#include "PIFF.h"
#include "struct.h"
#include "size.h"
#include <stdlib.h>

JNIEXPORT jobjectArray JNICALL Java_PIFF_algB(JNIEnv *env, jobject jobj, jstring jstr){

    int totalSize = 0;

    const char* rawString = (*env)->GetStringUTFChars(env, jstr, 0);
    int arrFlag[3] = {0,0,0};

    if(strcmp(rawString, "x") == 0)
        arrFlag[0] = 1;
    else if(strcmp(rawString, "y") == 0)
        arrFlag[1] = 1;
    else
        arrFlag[2] = 1;

   	for (int i = 0; i < initSize; i++)
    {
    	int xgap = arr[i].x_high - arr[i].x_low;
    	int ygap = arr[i].y_high - arr[i].y_low;
    	int zgap = arr[i].z_high - arr[i].z_low;
    	totalSize = totalSize + (xgap - (xgap - 1) * arrFlag[0]) * (ygap - (ygap - 1) * arrFlag[1]) * (zgap - (zgap - 1) * arrFlag[2]);
    }

    jobjectArray result;
    result = (jobjectArray)(*env)->NewObjectArray(env, totalSize, (*env)->FindClass(env, "java/lang/String"), 0);
    char numBuff[4];
    int index = 0;

    if(arrFlag[0])
    {
        for (int i = 0; i < initSize; i++)
    	    {
    		    char* temp = (char*)malloc(sizeof(arr[i].ID) + 25);
    		    for (int y = arr[i].y_low; y < arr[i].y_high; y++)
    		    {
    			    for (int z = arr[i].z_low; z < arr[i].z_high; z++)
    			    {
    			        strcpy(temp, arr[i].ID);
    					strcat(temp, " ");

    					sprintf(numBuff, "%d", arr[i].x_low);
    					strcat(temp, numBuff);
    					strcat(temp, " ");

    					sprintf(numBuff, "%d", arr[i].x_high);
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
            free(temp);
    		}
    	return result;
    }

    if(arrFlag[1])
    {
        for (int i = 0; i < initSize; i++)
    	    {
    		    char* temp = (char*)malloc(sizeof(arr[i].ID) + 25);
    		    for (int x = arr[i].x_low; x < arr[i].x_high; x++)
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

                        sprintf(numBuff, "%d", arr[i].y_low);
                        strcat(temp, numBuff);
                        strcat(temp, " ");

                        sprintf(numBuff, "%d", arr[i].y_high);
                        strcat(temp, numBuff);
                        strcat(temp, " ");

                        sprintf(numBuff, "%d", z);
                        strcat(temp, numBuff);
                        strcat(temp, " ");

                        sprintf(numBuff, "%d", z+1);
                        strcat(temp, numBuff);

                        z++;
    					(*env)->SetObjectArrayElement(env, result, index, (*env)->NewStringUTF(env, temp));
    					index++;
    				}
    			}
    		free(temp);
    		}
    	return result;
    }
    for (int i = 0; i < initSize; i++)
        {
            char* temp = (char*)malloc(sizeof(arr[i].ID) + 25);
    		for (int x = arr[i].x_low; x < arr[i].x_high; x++)
    		{
    			for (int y = arr[i].y_low; y < arr[i].y_high; y++)
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

                    sprintf(numBuff, "%d", y+2);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", arr[i].z_low);
                    strcat(temp, numBuff);
                    strcat(temp, " ");

                    sprintf(numBuff, "%d", arr[i].z_high);
                    strcat(temp, numBuff);

    			    (*env)->SetObjectArrayElement(env, result, index, (*env)->NewStringUTF(env, temp));
    			    index++;
    				}
    			}
            free(temp);
    		}
    return result;
}
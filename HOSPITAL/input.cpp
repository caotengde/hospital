#include <struct.h>
#include <malloc.h>
int main(){
	FILE *medrecord;
	int size;
	medrecord = fopen("medrecord.dat","rb+");
	printf("Please input the number of medical record:\n");
	scanf("%d", &size);
	MedRecord* med = (MedRecord*)malloc(size*sizeof(MedRecord));
	printf("Please input the medical record")
	fclose(medrecord);
} 

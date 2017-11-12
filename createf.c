#include "ops.h"

int install()
{	
	int info;

	printf("create disk...\n");
	info = createDisk(500);
	if (!info)
		printf("succes!");
}

int createDisk(int len)
{
	//FILE *f1;
	int l, i = 0;
	D1 = (struct Dformate*) calloc(1, sizeof(struct Dformate)); 
	
	strcpy(D1->name,  "disk1\0");
	D1->LDa = 0;
	D1->len = len;
	l = len;
	f = fopen(D1->name, "w");
	if (len > 0)
		fseek(f, len-1, SEEK_SET);
	putc(0, f);
	fflush(f);
	fseek(f, 0, SEEK_SET);
	setwrite(f, D1, sizeof(D1));
#if 0
	l = sizeof(char) * 20;
	while (l--) { 
		putc(D1->name[i++], f);
		printf("%ld\n", ftell(f));
	}
	putc(D1->len, f);
	putc(D1->LDa, f);
#endif
	fclose(f);
	
	createArea(D1->name, 80);
	return 0;
}

int createArea(char* s, int len)
{
	//FILE f;
	//
	int l, distance;
	struct Darea darea1;
	f = fopen(s, "r+");
	distance = (unsigned long*)(&(D1->LDa)) - (unsigned long*)(&(D1->name));
	fseek(f, distance*sizeof(long), SEEK_SET);
	l = ftell(f);
	D1->LDa += 1;
	setwrite(f, &(D1->LDa), sizeof(D1)+(int*)(&(D1->name))-&(D1->LDa));
	//putc(1, f);
	fseek(f, dmap.DforLen, SEEK_SET);
	darea1.start = 40;
	darea1.end = darea1.start + len;
	darea1.type = 1;
	setwrite(f, &darea1, sizeof(darea1));
#if 0
	putc(darea1.start, f);
	putc(darea1.end, f);
	putc(darea1.type, f);
#endif
	fflush(f);
	fclose(f);

}

int createFloder(char *s)
{	
	struct floder f1;
	f = fopen(D1->name, "r+");
	fseek(f,dmap.DforLen + dmap.DarLen, SEEK_SET);
	strcpy(s, f1.name);
	f1.Pname = NULL;
	f1.Cname = NULL;
	setwrite(f, &f1, sizeof(f1));
#if 0
	fputs(f1.name, f);
	fputs(f1.Pname, f);
	fputs(f1.Cname, f);
#endif

	fclose(f);
}

int setwrite(FILE *f2, void *p1, int len)
{
	char *s;
	
	s = (char *)calloc(1, len)+1;
	*(s+len) = '\0';	
	memcpy(s, p1, len+1);
	fputs(s, f2);
	free(s);
	return 0;
}

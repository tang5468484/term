#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DNAME 10

FILE *f;
struct Dformate *D1;



enum Dtype {
	aa = 1
};

struct Dformate {
	char name[10];
	int len;

//	struct *Da[3];
	int LDa;
};

struct Darea {
	int start;
	int end;
	int type;
};

struct Dmap {
	int DforLen;
	int DarLen;
	int FloLen;
	int FileLen;
};

struct floder {
	char name[20];
	char *Pname;
	char *Cname;
};

struct file {
	char name[20];
	char PFname;
	int len;
	int next;
};

struct Dmap dmap;
int install();
int creatdDisk(int len);
int setwrite(FILE *f2, void *p1, int len);

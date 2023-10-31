typedef enum {
	INT,
	LONG,
	FLOAT,
	STRING,
	VOID
} DataType;


typedef union {
	int intValue;
	long longValue;
	float floatValue;
	char *stringValue;
	void *voidValue;
} Value;

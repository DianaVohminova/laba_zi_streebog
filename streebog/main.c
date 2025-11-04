#include "main.h"

#ifdef SELF_TESTING
void self_testing()
{
	unsigned char h512[64] = {};

	for(int i = 0; i < TEST_VECTORS; i++)
	{
		hash_512(Message[i], MessageLength[i], h512);

		if(memcmp(h512, Hash_512[i], sizeof(unsigned char)*64))
		{
			printf("Тесты: провал\n");
			printf("Message: %d\n",i);
			printf("Length: %lld\n",MessageLength[i]);
			return;
		}
	}

	printf("Тесты: пройдены\n");
}
#endif

int main()
{
#ifdef SELF_TESTING
	self_testing();
#endif
	return 0;
}

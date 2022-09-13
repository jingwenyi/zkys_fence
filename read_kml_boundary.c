#include <stdio.h>
#include <string.h>



#define READ_FILE "../china_mogolia_boundary.kml"
#define WRITE_FILE "./china_mogolia_boundary.txt"




int main()
{
	FILE *read_fd;
	FILE * write_fd;

	read_fd = fopen(READ_FILE, "r");
	if(read_fd < 0)
	{
		printf("open %s error\n", READ_FILE);
		return -1;
	}
	
	write_fd = fopen(WRITE_FILE, "w");
	if(write_fd < 0)
	{
		printf("open %s error\n", WRITE_FILE);
		fclose(read_fd);
		return -1;
	}

	int flag = 0;
	int skip1 = 9;
	int skip2 = 10;
	int count = 9;
	char buf[1024];
	char tmp[1024];
	memset(buf, 0, sizeof(buf));
	while(fgets(buf, sizeof(buf), read_fd) != NULL)
	{
		int i;
		if(count-- == 0)
		{
			int j=0;
			memset(tmp, 0, sizeof(tmp));

			tmp[j++] = '{';
			
			//for(i=0; i<strlen(buf)-1; i++)  // lat,lng,alt
			for(i=0; i<strlen(buf)-3; i++) //lat,lng
			{
				if(buf[i] != ' ')
				{
					tmp[j++] = buf[i];
				}
			}

			tmp[j++] = '}';
			tmp[j++] = ',';
			tmp[j] = '\n';
			
			
			//printf("%s",tmp);
			fputs(tmp, write_fd);

			if(flag == 0)
			{
				flag = 1;
				j=0;
				memset(buf, 0, sizeof(buf));
				memset(tmp, 0, sizeof(tmp));
				if(fgets(buf, sizeof(buf), read_fd) != NULL)
				{
					tmp[j++] = '{';
			
					//for(i=0; i<strlen(buf)-1; i++)  // lat,lng,alt
					for(i=0; i<strlen(buf)-3; i++) //lat,lng
					{
						if(buf[i] != ' ')
						{
							tmp[j++] = buf[i];
						}
					}

					tmp[j++] = '}';
					tmp[j++] = ',';
					tmp[j] = '\n';
			
					//printf("%s",tmp);
					fputs(tmp, write_fd);
				}
			}

			count = 10;
			
			memset(buf, 0, sizeof(buf));
		}
	}

	fclose(read_fd);
	fclose(write_fd);
	
	return 0;
}




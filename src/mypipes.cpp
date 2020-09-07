// C program to implement one side of FIFO 
// This side writes first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string>
#include "mypipes.h"
#include <iostream>

//constructor
 mypipes::mypipes()
{
	
	// FIFO file path 
	
		fetchMe();
	
	
}
std::string mypipes::fetchMe() const
       {

                std::string examplestr = "thsi is an example";
                return examplestr;
        }
int mypipes::createPipe()
{

	return 0;
}
int mypipes::writePipeFork(std::string mydata)
{
	char arr2[80];
	pid_t pid = fork();

	/* child process */
	if (pid == 0)
	{
		int myPipe = open("/tmp/myfifo", O_WRONLY);

		int n = mydata.length();
		strcpy(arr2, mydata.c_str());
		//write(myPipe, "a", 1);
		write(myPipe, arr2, strlen(arr2) + 1);

		printf("Child process sent 'a'\n");
		close(myPipe);
	}
	return 0;
}
int mypipes::writePipe(std::string mydata)
{//while(1){
	//

	if (mydata.length() > 1) {
		//FIle Descriptor
		int  fd;
		std::cout << "creatingPipe" << std::endl;
		char * myfifo = "/tmp/myfifo";
		//mkfifo(myfifo, 0777);

		std::cout << "Waiting loop " << std::endl;
		// Open FIFO for write only 
		fd = open(myfifo, O_WRONLY);
		// assigning value to string mydata
		//char  arr1[80];
		char arr2[80];


		int n = mydata.length();

		// declaring character array 
		//char &arr2[n + 1];

		// copying the contents of the 
		// string to char array 
		strcpy(arr2, mydata.c_str());

		// Write the input arr2ing on FIFO 
			// and close it 
		write(fd, arr2, strlen(arr2) + 1);
		//write(fd, arr2, 80 + 1);
		close(fd);
	}
	//}
	return 0;
}
int mypipes::closePipe()
{
	
	return 0;
}




int addnumbers(int a , int b )
{
int sum ;
sum = a + b ;
return sum ;
}

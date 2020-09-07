#ifndef MYPIPES_H
#define MYPIPES_H

#define addnum(x,y) x+y
int addnumbers(int a , int b);
//#include <string>


class mypipes{
private:
	//int  fd;
	//char * myfifo;
	//char arr1;
	//char arr2;
public:
	mypipes();
        std::string fetchMe() const;
		int writePipeFork(std::string mydata);
		int createPipe();
		int writePipe(std::string mydata);
		int closePipe();

};
 #endif
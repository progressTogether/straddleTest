
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET = libstraddleTest.so
GCC = gcc
FLAGS = 

INCLUDE := -I /home/xiaohui/learnProject/straddleTest/include
LIBS    := 

#CFLAGS  := -fPIC -Wall -O2  $(INCLUDE)
CFLAGS  := -fPIC $(INCLUDE)
CXXFLAGS:= $(CFLAGS)
SHARE   := -shared  -o

all : $(TARGET)
	@cp -f $(TARGET) ./lib


$(TARGET) : $(OBJS)
	$(GCC) $(CXXFLAGS) $(SHARE) $@ $(OBJS)  $(LIBS)

#	$(GCC) $(SOURCE) $(FLAGS) -o $(TARGET) $(INCLUDE)
clean :
	@rm -f *.o $(TARGET) ./lib/$(TARGET)
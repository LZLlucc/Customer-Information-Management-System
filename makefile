# 定义编译器  
CC=gcc  
  
# 定义编译选项  
CFLAGS=-I.  
  
# 定义链接选项  
LDFLAGS=  
  
# 定义源文件和目标文件  
SRCS=$(wildcard *.c)  
OBJS=$(SRCS:.c=.o)  
TARGET=main  
  
# 默认目标  
all: $(TARGET)  
  
# 链接对象文件生成最终的可执行文件  
$(TARGET): $(OBJS)  
	$(CC) $(LDFLAGS) -o $@ $^  
  
# 编译C源文件生成对象文件  
%.o: %.c  
	$(CC) $(CFLAGS) -c -o $@ $<  
  
# 清理编译生成的文件  
clean:  
	rm -f $(OBJS) $(TARGET)  
  
# 伪目标，打印帮助信息  
.PHONY: help  
help:  
	@echo "Usage:"  
	@echo "  make        - Compile and link the program."  
	@echo "  make clean  - Remove object files and the executable."  
	@echo "  make help   - Show this help message."

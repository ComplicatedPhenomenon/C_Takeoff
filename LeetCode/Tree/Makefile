CC = gcc
CFLAGS = -I. -g -Wall 


TARGET = generateABST
TARGET1 = countCompleteTreeNodes_2
TARGET2 = balancedBinaryTree
TARGET3 = pathSum

#all:
#	$(TARGET) $(TARGET1) $(TARGET2) $(TARGET3)

# `generateABST` is the default target and will be run when we run "make"
$(TARGET): $(TARGET).c tree.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c tree.o

$(TARGET1): $(TARGET1).c tree.o
	$(CC) $(CFLAGS)  -o $(TARGET1) $(TARGET1).c tree.o -lm

$(TARGET2): $(TARGET2).c tree.o
	$(CC) $(CFLAGS)  -o $(TARGET2) $(TARGET2).c tree.o

$(TARGET3): $(TARGET3).c tree.o
	$(CC) $(CFLAGS)  -o $(TARGET3) $(TARGET3).c tree.o

tree.o: tree.c  
	$(CC) -c $(CFLAGS) -o tree.o tree.c

clean: 
	rm $(TARGET) $(TARGET1)  $(TARGET2)  $(TARGET3) tree.o
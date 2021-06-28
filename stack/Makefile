bin=stack
file_list=main.o stack.o
cc=gcc

$(bin):$(file_list)
	$(cc) -o $@ $^

%.o:%.c
	$(cc) -c $<

.PHONY:clean
clean:
	rm $(bin) $(file_list)

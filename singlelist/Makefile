bin=slist
file_list=main.o slist.o
cc=gcc

$(bin):$(file_list)
	$(cc) -o $@ $^

%.o:%.c
	$(cc) -c $<

.PHONY:clean
clean:
	rm $(bin) $(file_list)

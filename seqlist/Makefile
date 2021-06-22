bin=seqlist
file_list=SeqList.o main.o
cc=gcc

$(bin):$(file_list)
	$(cc) -o $@ $^
%.o:%.c
	$(cc) -c $<

.PHONY:clean
clean:
	rm -f $(bin) $(file_list)

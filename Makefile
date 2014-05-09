#         _.._   _..---.                                
#      .-"    ;-"       \                               
#     /      /           |                              
#    |      |       _=   |      I SPY WITH MY LITTLE EYE
#    ;   _.-'\__.-')     |      ................. A DICK
#     `-'      |   |    ;                               
#              |  /;   /      _,                        
#            .-.;.-=-./-""-.-` _`                       
#           /   |     \     \-` `,                      
#          |    |      |     |                          
#          |____|______|     |                          
#           \0 / \0   /      /                          
#        .--.-""-.`--'     .'                           
#       (#   )          ,  \                            
#       ('--'          /\`  \                           
#        \       ,,  .'      \                          
#         `-._    _.'\        \                         
#             `""`    \        \                        
#
CC=gcc
CFLAGS=-I. -lcurses

pfans: main.o
	$(CC) -o pfans main.o $(CFLAGS)

main.o: src/main.c src/config.h
	$(CC) -c src/main.c -o main.o $(CFLAGS)

clean:
	rm *.o pfans

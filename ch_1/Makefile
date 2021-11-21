CC = cc
FLAGS = -Wall -Werror -Wpedantic -Wextra
BIN = ./bin

$(BIN):
	mkdir $(BIN)

%: %.c $(BIN)
	$(CC) $(FLAGS) -o $(BIN)/$@ $< -lm

clean:
	rm -f $(BIN)/*
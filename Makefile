# Makefile for EECS 348 Lab 8
# Compiles and runs both C programs

CC = gcc

FOOTBALL = football_score
TEMP = temperature_conversion

FOOTBALL_SRC = football_score.c
TEMP_SRC = temperature_conversion.c

all: $(FOOTBALL) $(TEMP)

$(FOOTBALL): $(FOOTBALL_SRC)
      $(CC) -o $(FOOTBALL) $(FOOTBALL_SRC)

$(TEMP): $(TEMP_SRC)
      $(CC) -o $(TEMP) $(TEMP_SRC)

run-football: $(FOOTBALL)
      ./$(FOOTBALL)

run-temp: $(TEMP)
      ./$(TEMP)

clean:
      rm -f $(FOOTBALL) $(TEMP)
